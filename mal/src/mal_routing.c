/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 CNES
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* */
#include "mal.h"

// TODO: Implements an hashtable.
struct _mal_routing_t {
  int max;
  int idx;
  mal_routing_handler_t **handlers;

  mal_endpoint_t *mal_endpoint;
  void *state;
};

// Default size for routing table
#define MAL_ROUTING_DFLT_SIZE 20

mal_routing_t *mal_routing_new(mal_endpoint_t *mal_endpoint, void *state) {
  mal_routing_t *self = (mal_routing_t *) malloc(sizeof(mal_routing_t));
  if (!self)
    return NULL;

  self ->state = state;
  self->mal_endpoint = mal_endpoint;

  self->handlers = (mal_routing_handler_t **) calloc(MAL_ROUTING_DFLT_SIZE, sizeof(mal_routing_handler_t *));
  if (self->handlers == NULL) {
    free(self);
    return NULL;
  }

  self->max = MAL_ROUTING_DFLT_SIZE;
  self->idx = 0;

  return self;
}

void mal_routing_destroy(mal_routing_t **self_p) {
  if (self_p && *self_p) {
    mal_routing_t *self = *self_p;

    for (int i=0; i<self->idx; i++) {
      free(self->handlers[i]);
    }
    free(self->handlers);

    free(self);
    *self_p = NULL;
  }
}

void *mal_routing_get_state(mal_routing_t *self) {
  return self->state;
}

//}
//struct _mal_routing_consumer_send_handler_t {
//};

struct _mal_routing_provider_send_handler_t {
  mal_routing_on_message_fn *on_send;
};

struct _mal_routing_consumer_submit_handler_t {
  mal_routing_on_message_fn *on_ack;
};

struct _mal_routing_provider_submit_handler_t {
  mal_routing_on_message_fn *on_submit;
};

struct _mal_routing_consumer_request_handler_t {
  mal_routing_on_message_fn *on_response;
};

struct _mal_routing_provider_request_handler_t {
  mal_routing_on_message_fn *on_request;
};

struct _mal_routing_consumer_invoke_handler_t {
  mal_routing_on_message_fn *on_ack;
  mal_routing_on_message_fn *on_response;
};

struct _mal_routing_provider_invoke_handler_t {
  mal_routing_on_message_fn *on_invoke;
};

struct _mal_routing_consumer_progress_handler_t {
  mal_routing_on_message_fn *on_ack;
  mal_routing_on_message_fn *on_update;
  mal_routing_on_message_fn *on_response;
};

struct _mal_routing_provider_progress_handler_t {
  mal_routing_on_message_fn *on_progress;
};

struct _mal_routing_provider_pubsub_handler_t {
  mal_routing_on_message_fn *on_publish_error;
  mal_routing_on_message_fn *on_publish_register_ack;
  mal_routing_on_message_fn *on_publish_deregister_ack;
};

struct _mal_routing_consumer_pubsub_handler_t {
  mal_routing_on_message_fn *on_register_ack;
  mal_routing_on_message_fn *on_deregister_ack;
  mal_routing_on_message_fn *on_notify;
};

struct _mal_routing_broker_pubsub_handler_t {
  mal_routing_on_message_fn *on_notify_error;
  mal_routing_on_message_fn *on_register;
  mal_routing_on_message_fn *on_deregister;
  mal_routing_on_message_fn *on_publish;
  mal_routing_on_message_fn *on_publish_register;
  mal_routing_on_message_fn *on_publish_deregister;
};

struct _mal_routing_handler_t {
  handler_type_t type;
  mal_ushort_t area;
  mal_uoctet_t area_version;
  mal_ushort_t service;
  mal_ushort_t operation;

union {
//    mal_routing_consumer_send_handler_t consumer_send_handler;
    mal_routing_provider_send_handler_t provider_send_handler;
    mal_routing_consumer_submit_handler_t consumer_submit_handler;
    mal_routing_provider_submit_handler_t provider_submit_handler;
    mal_routing_consumer_request_handler_t consumer_request_handler;
    mal_routing_provider_request_handler_t provider_request_handler;
    mal_routing_consumer_invoke_handler_t consumer_invoke_handler;
    mal_routing_provider_invoke_handler_t provider_invoke_handler;
    mal_routing_consumer_progress_handler_t consumer_progress_handler;
    mal_routing_provider_progress_handler_t provider_progress_handler;
    mal_routing_consumer_pubsub_handler_t consumer_pubsub_handler;
    mal_routing_provider_pubsub_handler_t provider_pubsub_handler;
    mal_routing_broker_pubsub_handler_t broker_pubsub_handler;
  } spec;
};

int mal_routing_register_handler(mal_routing_t *mal_routing, mal_routing_handler_t *handler) {
  if (mal_routing->idx < mal_routing->max) {
    // Includes the structure in the table
    mal_routing->handlers[mal_routing->idx++] = handler;
    return 0;
  } else {
    clog_error(mal_logger, "Error :: Cannot register more than %d handlers\n", mal_routing->max);
    return -1;
  }
}

int mal_routing_remove_handler(
    mal_routing_t *mal_routing,
    handler_type_t type,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation) {
  clog_info(mal_logger, " *** mal_routing_remove_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  int found = -1;
  for (int i=0; i<mal_routing->idx; i++) {
    if ((mal_routing->handlers[i] != NULL) &&
        (mal_routing->handlers[i]->type == type) &&
        (mal_routing->handlers[i]->area == area) &&
        (mal_routing->handlers[i]->area_version == area_version) &&
        (mal_routing->handlers[i]->service == service) &&
        (mal_routing->handlers[i]->operation == operation)) {
      found = i;
      break;
    }
  }

  if (found == -1) {
    clog_warning(mal_logger, " *** mal_routing_remove_handler: Not found\n");
    return -1;
  }

  mal_routing->idx -= 1;
  for (int i=found; i<mal_routing->idx; i++) {
    mal_routing->handlers[i] = mal_routing->handlers[i+1];
  }
  mal_routing->handlers[mal_routing->idx] = NULL;

  clog_debug(mal_logger, " *** mal_routing_remove_handler: OK\n");
  return 0;
}

mal_routing_handler_t *mal_routing_new_handler(
    handler_type_t type,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation) {
  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = (mal_routing_handler_t *) malloc(sizeof(mal_routing_handler_t));
  if (handler != NULL) {
    handler->type = type;
    handler->area = area;
    handler->area_version = area_version;
    handler->service = service;
    handler->operation = operation;
  }
  return handler;
}

int mal_routing_register_provider_send_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_send) {
  clog_info(mal_logger, " *** mal_routing_register_provider_send_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_PROVIDER_SEND_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.provider_send_handler.on_send = on_send;
  return mal_routing_register_handler(mal_routing, handler);
}

int mal_routing_register_provider_submit_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_submit) {
  clog_info(mal_logger, " *** mal_routing_register_provider_submit_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_PROVIDER_SUBMIT_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.provider_submit_handler.on_submit = on_submit;
  return mal_routing_register_handler(mal_routing, handler);
}

int mal_routing_register_consumer_submit_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack) {
  clog_info(mal_logger, " *** mal_routing_register_consumer_submit_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_CONSUMER_SUBMIT_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.consumer_submit_handler.on_ack = on_ack;
  return mal_routing_register_handler(mal_routing, handler);
}

int mal_routing_register_provider_request_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_request) {
  clog_info(mal_logger, " *** mal_routing_register_provider_request_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_PROVIDER_REQUEST_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.provider_request_handler.on_request = on_request;
  return mal_routing_register_handler(mal_routing, handler);
}

int mal_routing_register_consumer_request_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_response) {
  clog_info(mal_logger, " *** mal_routing_register_consumer_request_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_CONSUMER_REQUEST_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.consumer_request_handler.on_response = on_response;
  return mal_routing_register_handler(mal_routing, handler);
}


int mal_routing_register_provider_invoke_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_invoke) {
  clog_info(mal_logger, " *** mal_routing_register_provider_invoke_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_PROVIDER_INVOKE_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.provider_invoke_handler.on_invoke = on_invoke;
  return mal_routing_register_handler(mal_routing, handler);
}

int mal_routing_register_consumer_invoke_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack,
    mal_routing_on_message_fn *on_response) {
  clog_info(mal_logger, " *** mal_routing_register_consumer_invoke_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_CONSUMER_INVOKE_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.consumer_invoke_handler.on_ack = on_ack;
  handler->spec.consumer_invoke_handler.on_response = on_response;
  return mal_routing_register_handler(mal_routing, handler);
}

int mal_routing_register_provider_progress_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_progress) {
  clog_info(mal_logger, " *** mal_routing_register_provider_progress_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_PROVIDER_PROGRESS_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.provider_progress_handler.on_progress = on_progress;
  return mal_routing_register_handler(mal_routing, handler);
}

int mal_routing_register_consumer_progress_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack,
    mal_routing_on_message_fn *on_update,
    mal_routing_on_message_fn *on_response) {
  clog_info(mal_logger, " *** mal_routing_register_consumer_progress_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_CONSUMER_PROGRESS_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.consumer_progress_handler.on_ack = on_ack;
  handler->spec.consumer_progress_handler.on_update = on_update;
  handler->spec.consumer_progress_handler.on_response = on_response;
  return mal_routing_register_handler(mal_routing, handler);
}

int mal_routing_register_provider_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_publish_error,
    mal_routing_on_message_fn *on_publish_register_ack,
    mal_routing_on_message_fn *on_publish_deregister_ack) {
  clog_info(mal_logger, " *** mal_routing_register_provider_pubsub_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_PROVIDER_PUBSUB_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.provider_pubsub_handler.on_publish_error = on_publish_error;
  handler->spec.provider_pubsub_handler.on_publish_register_ack = on_publish_register_ack;
  handler->spec.provider_pubsub_handler.on_publish_deregister_ack = on_publish_deregister_ack;
  return mal_routing_register_handler(mal_routing, handler);
}

int mal_routing_register_consumer_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_register_ack,
    mal_routing_on_message_fn *on_deregister_ack,
    mal_routing_on_message_fn *on_notify) {
  clog_info(mal_logger, " *** mal_routing_register_consumer_pubsub_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_CONSUMER_PUBSUB_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.consumer_pubsub_handler.on_register_ack = on_register_ack;
  handler->spec.consumer_pubsub_handler.on_deregister_ack = on_deregister_ack;
  handler->spec.consumer_pubsub_handler.on_notify = on_notify;
  return mal_routing_register_handler(mal_routing, handler);
}

int mal_routing_register_broker_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_notify_error,
    mal_routing_on_message_fn *on_register,
    mal_routing_on_message_fn *on_deregister,
    mal_routing_on_message_fn *on_publish,
    mal_routing_on_message_fn *on_publish_register,
    mal_routing_on_message_fn *on_publish_deregister) {
  clog_info(mal_logger, " *** mal_routing_register_broker_pubsub_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  // Allocates a new structure and initialize it
  mal_routing_handler_t *handler = mal_routing_new_handler(MAL_ACTOR_BROKER_PUBSUB_HANDLER, area, area_version, service, operation);
  if (handler == NULL) return -1;

  handler->spec.broker_pubsub_handler.on_notify_error = on_notify_error;
  handler->spec.broker_pubsub_handler.on_register = on_register;
  handler->spec.broker_pubsub_handler.on_deregister = on_deregister;
  handler->spec.broker_pubsub_handler.on_publish = on_publish;
  handler->spec.broker_pubsub_handler.on_publish_register = on_publish_register;
  handler->spec.broker_pubsub_handler.on_publish_deregister = on_publish_deregister;
  return mal_routing_register_handler(mal_routing, handler);

}

mal_routing_handler_t* mal_routing_get_handler(
    mal_routing_t *mal_routing,
    handler_type_t type,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation) {
  clog_info(mal_logger, " *** mal_routing_get_handler: %hd %hhd %hd %hd\n", area, area_version, service, operation);

  for (int i=0; i<mal_routing->idx; i++) {
    if ((mal_routing->handlers[i]->type == type) &&
        (mal_routing->handlers[i]->area == area) &&
        (mal_routing->handlers[i]->area_version == area_version) &&
        (mal_routing->handlers[i]->service == service) &&
        (mal_routing->handlers[i]->operation == operation)) {

     clog_debug(mal_logger, " *** mal_routing_get_handler: OK\n");
     return mal_routing->handlers[i];
    }
  }
  return NULL;
}

int mal_routing_handle(
    mal_routing_t *self,
    mal_message_t *message) {
  int rc = 0;
  mal_ctx_t *mal_ctx = mal_endpoint_get_mal_ctx(self->mal_endpoint);

  clog_info(mal_logger, " *** mal_routing_handle: ");
  if (clog_is_loggable(mal_logger, CLOG_INFO_LEVEL)) mal_message_print(message);
  clog_info(mal_logger, "\n");

  switch (mal_message_get_interaction_type(message)) {
  case MAL_INTERACTIONTYPE_SEND: {
    if (mal_message_get_interaction_stage(message) == MAL_IP_STAGE_SEND) {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_SEND/MAL_IP_STAGE_SEND\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_PROVIDER_SEND_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.provider_send_handler.on_send(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
    } else {
      clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_BAD_IP_STAGE_MSG);
      rc = MAL_ROUTING_BAD_IP_STAGE;
    }
    break;
  }
  case MAL_INTERACTIONTYPE_SUBMIT: {
    switch (mal_message_get_interaction_stage(message)) {
    case MAL_IP_STAGE_SUBMIT: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_SUBMIT/MAL_IP_STAGE_SUBMIT\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_PROVIDER_SUBMIT_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.provider_submit_handler.on_submit(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_SUBMIT_ACK: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_SUBMIT/MAL_IP_STAGE_SUBMIT_ACK\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_CONSUMER_SUBMIT_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc= handler->spec.consumer_submit_handler.on_ack(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    default:
      clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_BAD_IP_STAGE_MSG);
      rc = MAL_ROUTING_BAD_IP_STAGE;
    }
    break;
  }
  case MAL_INTERACTIONTYPE_REQUEST: {
    switch (mal_message_get_interaction_stage(message)) {
    case MAL_IP_STAGE_REQUEST: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_REQUEST/MAL_IP_STAGE_REQUEST\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_PROVIDER_REQUEST_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.provider_request_handler.on_request(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_REQUEST_RESPONSE: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_REQUEST/MAL_IP_STAGE_REQUEST_RESPONSE\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_CONSUMER_REQUEST_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc =handler->spec.consumer_request_handler.on_response(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    default:
      clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_BAD_IP_STAGE_MSG);
      rc = MAL_ROUTING_BAD_IP_STAGE;
    }
    break;
  }
  case MAL_INTERACTIONTYPE_INVOKE: {
    switch (mal_message_get_interaction_stage(message)) {
    case MAL_IP_STAGE_INVOKE: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_INVOKE/MAL_IP_STAGE_INVOKE\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_PROVIDER_INVOKE_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.provider_invoke_handler.on_invoke(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_INVOKE_ACK: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_INVOKE/MAL_IP_STAGE_INVOKE_ACK\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_CONSUMER_INVOKE_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.consumer_invoke_handler.on_ack(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_INVOKE_RESPONSE: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_INVOKE/MAL_IP_STAGE_INVOKE_RESPONSE\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_CONSUMER_INVOKE_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.consumer_invoke_handler.on_response(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    default:
      clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_BAD_IP_STAGE_MSG);
      rc = MAL_ROUTING_BAD_IP_STAGE;
    }
    break;
  }
  case MAL_INTERACTIONTYPE_PROGRESS: {
    switch (mal_message_get_interaction_stage(message)) {
    case MAL_IP_STAGE_PROGRESS: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PROGRESS/MAL_IP_STAGE_PROGRESS\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_PROVIDER_PROGRESS_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.provider_progress_handler.on_progress(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_PROGRESS_ACK: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PROGRESS/MAL_IP_STAGE_PROGRESS_ACK\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_CONSUMER_PROGRESS_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.consumer_progress_handler.on_ack(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_PROGRESS_UPDATE: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PROGRESS/MAL_IP_STAGE_PROGRESS_UPDATE\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_CONSUMER_PROGRESS_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.consumer_progress_handler.on_update(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_PROGRESS_RESPONSE: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PROGRESS/MAL_IP_STAGE_PROGRESS_RESPONSE\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_CONSUMER_PROGRESS_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.consumer_progress_handler.on_response(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    default:
      clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_BAD_IP_STAGE_MSG);
      rc = MAL_ROUTING_BAD_IP_STAGE;
    }
    break;
  }
  case MAL_INTERACTIONTYPE_PUBSUB: {
    switch (mal_message_get_interaction_stage(message)) {
    case MAL_IP_STAGE_PUBSUB_REGISTER: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PUBSUB/MAL_IP_STAGE_PUBSUB_REGISTER\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_BROKER_PUBSUB_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.broker_pubsub_handler.on_register(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_PUBSUB_REGISTER_ACK: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PUBSUB/MAL_IP_STAGE_PUBSUB_REGISTER_ACK\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_CONSUMER_PUBSUB_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.consumer_pubsub_handler.on_register_ack(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER: {
      clog_error(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PUBSUB/MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER\n");
      // Should never happen with ZMQ Transport

        mal_routing_handler_t* handler = mal_routing_get_handler(
            self,
            MAL_ACTOR_BROKER_PUBSUB_HANDLER,
            mal_message_get_service_area(message),
            mal_message_get_area_version(message),
            mal_message_get_service(message),
            mal_message_get_operation(message));

        if (handler != NULL) {
          rc = handler->spec.broker_pubsub_handler.on_publish_register(self->state, mal_ctx, self->mal_endpoint, message);
        } else {
          clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
          rc = MAL_ROUTING_NO_HANDLER;
        }
      break;
    }
    case MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER_ACK: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PUBSUB/MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER_ACK\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_PROVIDER_PUBSUB_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.provider_pubsub_handler.on_publish_register_ack(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_PUBSUB_PUBLISH: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PUBSUB/MAL_IP_STAGE_PUBSUB_PUBLISH\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_BROKER_PUBSUB_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.broker_pubsub_handler.on_publish(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_PUBSUB_NOTIFY: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PUBSUB/MAL_IP_STAGE_PUBSUB_NOTIFY\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_CONSUMER_PUBSUB_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.consumer_pubsub_handler.on_notify(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_PUBSUB_DEREGISTER: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PUBSUB/MAL_IP_STAGE_PUBSUB_DEREGISTER\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_BROKER_PUBSUB_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.broker_pubsub_handler.on_deregister(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_PUBSUB_DEREGISTER_ACK: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PUBSUB/MAL_IP_STAGE_PUBSUB_DEREGISTER_ACK\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_CONSUMER_PUBSUB_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.consumer_pubsub_handler.on_deregister_ack(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER: {
      clog_error(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PUBSUB/MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER\n");
      // Should never happen  with ZMQ Transport

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_BROKER_PUBSUB_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.broker_pubsub_handler.on_publish_deregister(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    case MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER_ACK: {
      clog_debug(mal_logger, " *** mal_routing_handle: MAL_INTERACTIONTYPE_PUBSUB/MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER_ACK\n");

      mal_routing_handler_t* handler = mal_routing_get_handler(
          self,
          MAL_ACTOR_PROVIDER_PUBSUB_HANDLER,
          mal_message_get_service_area(message),
          mal_message_get_area_version(message),
          mal_message_get_service(message),
          mal_message_get_operation(message));

      if (handler != NULL) {
        rc = handler->spec.provider_pubsub_handler.on_publish_deregister_ack(self->state, mal_ctx, self->mal_endpoint, message);
      } else {
        clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_NO_HANDLER_MSG);
        rc = MAL_ROUTING_NO_HANDLER;
      }
      break;
    }
    default:
      clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_BAD_IP_STAGE_MSG);
      rc = MAL_ROUTING_BAD_IP_STAGE;
    }
    break;
  }
  default:
    clog_error(mal_logger, "ERROR: %s\n", MAL_ROUTING_UNKNOW_INTERACTION_TYPE_MSG);
    rc = MAL_ROUTING_UNKNOW_INTERACTION_TYPE;
  }

  return rc;
}

void mal_routing_test(bool verbose) {
  printf(" * mal_routing: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

