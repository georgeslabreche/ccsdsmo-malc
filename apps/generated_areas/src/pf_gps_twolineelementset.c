#include "pf.h"


// structure definition for composite pf_gps_twolineelementset
struct _pf_gps_twolineelementset_t {
  bool f_catalogno_is_present;
  mal_integer_t f_catalogno;
  mal_string_t * f_classification;
  bool f_idyear_is_present;
  mal_integer_t f_idyear;
  bool f_idlaunchno_is_present;
  mal_integer_t f_idlaunchno;
  mal_string_t * f_idpiece;
  bool f_epochyear_is_present;
  mal_integer_t f_epochyear;
  bool f_epochday_is_present;
  mal_integer_t f_epochday;
  bool f_epochsecond_is_present;
  mal_double_t f_epochsecond;
  bool f_meanmotiond1_is_present;
  mal_double_t f_meanmotiond1;
  bool f_meanmotiond2_is_present;
  mal_double_t f_meanmotiond2;
  bool f_dragterm_is_present;
  mal_double_t f_dragterm;
  bool f_id_is_present;
  mal_integer_t f_id;
  bool f_inclination_is_present;
  mal_double_t f_inclination;
  bool f_raan_is_present;
  mal_double_t f_raan;
  bool f_eccentricity_is_present;
  mal_double_t f_eccentricity;
  bool f_argumentofperigee_is_present;
  mal_double_t f_argumentofperigee;
  bool f_meananomaly_is_present;
  mal_double_t f_meananomaly;
  bool f_meanmotion_is_present;
  mal_double_t f_meanmotion;
  bool f_numrevolutions_is_present;
  mal_integer_t f_numrevolutions;
};

// fields accessors for composite pf_gps_twolineelementset
bool pf_gps_twolineelementset_catalogno_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_catalogno_is_present;
}
void pf_gps_twolineelementset_catalogno_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_catalogno_is_present = is_present;
}
mal_integer_t pf_gps_twolineelementset_get_catalogno(pf_gps_twolineelementset_t * self)
{
  return self->f_catalogno;
}
void pf_gps_twolineelementset_set_catalogno(pf_gps_twolineelementset_t * self, mal_integer_t f_catalogno)
{
  self->f_catalogno = f_catalogno;
}
mal_string_t * pf_gps_twolineelementset_get_classification(pf_gps_twolineelementset_t * self)
{
  return self->f_classification;
}
void pf_gps_twolineelementset_set_classification(pf_gps_twolineelementset_t * self, mal_string_t * f_classification)
{
  self->f_classification = f_classification;
}
bool pf_gps_twolineelementset_idyear_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_idyear_is_present;
}
void pf_gps_twolineelementset_idyear_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_idyear_is_present = is_present;
}
mal_integer_t pf_gps_twolineelementset_get_idyear(pf_gps_twolineelementset_t * self)
{
  return self->f_idyear;
}
void pf_gps_twolineelementset_set_idyear(pf_gps_twolineelementset_t * self, mal_integer_t f_idyear)
{
  self->f_idyear = f_idyear;
}
bool pf_gps_twolineelementset_idlaunchno_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_idlaunchno_is_present;
}
void pf_gps_twolineelementset_idlaunchno_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_idlaunchno_is_present = is_present;
}
mal_integer_t pf_gps_twolineelementset_get_idlaunchno(pf_gps_twolineelementset_t * self)
{
  return self->f_idlaunchno;
}
void pf_gps_twolineelementset_set_idlaunchno(pf_gps_twolineelementset_t * self, mal_integer_t f_idlaunchno)
{
  self->f_idlaunchno = f_idlaunchno;
}
mal_string_t * pf_gps_twolineelementset_get_idpiece(pf_gps_twolineelementset_t * self)
{
  return self->f_idpiece;
}
void pf_gps_twolineelementset_set_idpiece(pf_gps_twolineelementset_t * self, mal_string_t * f_idpiece)
{
  self->f_idpiece = f_idpiece;
}
bool pf_gps_twolineelementset_epochyear_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_epochyear_is_present;
}
void pf_gps_twolineelementset_epochyear_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_epochyear_is_present = is_present;
}
mal_integer_t pf_gps_twolineelementset_get_epochyear(pf_gps_twolineelementset_t * self)
{
  return self->f_epochyear;
}
void pf_gps_twolineelementset_set_epochyear(pf_gps_twolineelementset_t * self, mal_integer_t f_epochyear)
{
  self->f_epochyear = f_epochyear;
}
bool pf_gps_twolineelementset_epochday_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_epochday_is_present;
}
void pf_gps_twolineelementset_epochday_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_epochday_is_present = is_present;
}
mal_integer_t pf_gps_twolineelementset_get_epochday(pf_gps_twolineelementset_t * self)
{
  return self->f_epochday;
}
void pf_gps_twolineelementset_set_epochday(pf_gps_twolineelementset_t * self, mal_integer_t f_epochday)
{
  self->f_epochday = f_epochday;
}
bool pf_gps_twolineelementset_epochsecond_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_epochsecond_is_present;
}
void pf_gps_twolineelementset_epochsecond_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_epochsecond_is_present = is_present;
}
mal_double_t pf_gps_twolineelementset_get_epochsecond(pf_gps_twolineelementset_t * self)
{
  return self->f_epochsecond;
}
void pf_gps_twolineelementset_set_epochsecond(pf_gps_twolineelementset_t * self, mal_double_t f_epochsecond)
{
  self->f_epochsecond = f_epochsecond;
}
bool pf_gps_twolineelementset_meanmotiond1_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_meanmotiond1_is_present;
}
void pf_gps_twolineelementset_meanmotiond1_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_meanmotiond1_is_present = is_present;
}
mal_double_t pf_gps_twolineelementset_get_meanmotiond1(pf_gps_twolineelementset_t * self)
{
  return self->f_meanmotiond1;
}
void pf_gps_twolineelementset_set_meanmotiond1(pf_gps_twolineelementset_t * self, mal_double_t f_meanmotiond1)
{
  self->f_meanmotiond1 = f_meanmotiond1;
}
bool pf_gps_twolineelementset_meanmotiond2_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_meanmotiond2_is_present;
}
void pf_gps_twolineelementset_meanmotiond2_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_meanmotiond2_is_present = is_present;
}
mal_double_t pf_gps_twolineelementset_get_meanmotiond2(pf_gps_twolineelementset_t * self)
{
  return self->f_meanmotiond2;
}
void pf_gps_twolineelementset_set_meanmotiond2(pf_gps_twolineelementset_t * self, mal_double_t f_meanmotiond2)
{
  self->f_meanmotiond2 = f_meanmotiond2;
}
bool pf_gps_twolineelementset_dragterm_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_dragterm_is_present;
}
void pf_gps_twolineelementset_dragterm_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_dragterm_is_present = is_present;
}
mal_double_t pf_gps_twolineelementset_get_dragterm(pf_gps_twolineelementset_t * self)
{
  return self->f_dragterm;
}
void pf_gps_twolineelementset_set_dragterm(pf_gps_twolineelementset_t * self, mal_double_t f_dragterm)
{
  self->f_dragterm = f_dragterm;
}
bool pf_gps_twolineelementset_id_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_id_is_present;
}
void pf_gps_twolineelementset_id_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_id_is_present = is_present;
}
mal_integer_t pf_gps_twolineelementset_get_id(pf_gps_twolineelementset_t * self)
{
  return self->f_id;
}
void pf_gps_twolineelementset_set_id(pf_gps_twolineelementset_t * self, mal_integer_t f_id)
{
  self->f_id = f_id;
}
bool pf_gps_twolineelementset_inclination_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_inclination_is_present;
}
void pf_gps_twolineelementset_inclination_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_inclination_is_present = is_present;
}
mal_double_t pf_gps_twolineelementset_get_inclination(pf_gps_twolineelementset_t * self)
{
  return self->f_inclination;
}
void pf_gps_twolineelementset_set_inclination(pf_gps_twolineelementset_t * self, mal_double_t f_inclination)
{
  self->f_inclination = f_inclination;
}
bool pf_gps_twolineelementset_raan_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_raan_is_present;
}
void pf_gps_twolineelementset_raan_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_raan_is_present = is_present;
}
mal_double_t pf_gps_twolineelementset_get_raan(pf_gps_twolineelementset_t * self)
{
  return self->f_raan;
}
void pf_gps_twolineelementset_set_raan(pf_gps_twolineelementset_t * self, mal_double_t f_raan)
{
  self->f_raan = f_raan;
}
bool pf_gps_twolineelementset_eccentricity_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_eccentricity_is_present;
}
void pf_gps_twolineelementset_eccentricity_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_eccentricity_is_present = is_present;
}
mal_double_t pf_gps_twolineelementset_get_eccentricity(pf_gps_twolineelementset_t * self)
{
  return self->f_eccentricity;
}
void pf_gps_twolineelementset_set_eccentricity(pf_gps_twolineelementset_t * self, mal_double_t f_eccentricity)
{
  self->f_eccentricity = f_eccentricity;
}
bool pf_gps_twolineelementset_argumentofperigee_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_argumentofperigee_is_present;
}
void pf_gps_twolineelementset_argumentofperigee_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_argumentofperigee_is_present = is_present;
}
mal_double_t pf_gps_twolineelementset_get_argumentofperigee(pf_gps_twolineelementset_t * self)
{
  return self->f_argumentofperigee;
}
void pf_gps_twolineelementset_set_argumentofperigee(pf_gps_twolineelementset_t * self, mal_double_t f_argumentofperigee)
{
  self->f_argumentofperigee = f_argumentofperigee;
}
bool pf_gps_twolineelementset_meananomaly_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_meananomaly_is_present;
}
void pf_gps_twolineelementset_meananomaly_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_meananomaly_is_present = is_present;
}
mal_double_t pf_gps_twolineelementset_get_meananomaly(pf_gps_twolineelementset_t * self)
{
  return self->f_meananomaly;
}
void pf_gps_twolineelementset_set_meananomaly(pf_gps_twolineelementset_t * self, mal_double_t f_meananomaly)
{
  self->f_meananomaly = f_meananomaly;
}
bool pf_gps_twolineelementset_meanmotion_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_meanmotion_is_present;
}
void pf_gps_twolineelementset_meanmotion_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_meanmotion_is_present = is_present;
}
mal_double_t pf_gps_twolineelementset_get_meanmotion(pf_gps_twolineelementset_t * self)
{
  return self->f_meanmotion;
}
void pf_gps_twolineelementset_set_meanmotion(pf_gps_twolineelementset_t * self, mal_double_t f_meanmotion)
{
  self->f_meanmotion = f_meanmotion;
}
bool pf_gps_twolineelementset_numrevolutions_is_present(pf_gps_twolineelementset_t * self)
{
  return self->f_numrevolutions_is_present;
}
void pf_gps_twolineelementset_numrevolutions_set_present(pf_gps_twolineelementset_t * self, bool is_present)
{
  self->f_numrevolutions_is_present = is_present;
}
mal_integer_t pf_gps_twolineelementset_get_numrevolutions(pf_gps_twolineelementset_t * self)
{
  return self->f_numrevolutions;
}
void pf_gps_twolineelementset_set_numrevolutions(pf_gps_twolineelementset_t * self, mal_integer_t f_numrevolutions)
{
  self->f_numrevolutions = f_numrevolutions;
}

// default constructor
pf_gps_twolineelementset_t * pf_gps_twolineelementset_new(void)
{
  pf_gps_twolineelementset_t *self = (pf_gps_twolineelementset_t *) calloc(1, sizeof(pf_gps_twolineelementset_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_gps_twolineelementset_add_encoding_length_malbinary(pf_gps_twolineelementset_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_catalogno_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_catalogno_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_catalogno, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_classification != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_classification != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_classification, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_idyear_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_idyear_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_idyear, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_idlaunchno_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_idlaunchno_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_idlaunchno, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_idpiece != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_idpiece != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_idpiece, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_epochyear_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_epochyear_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_epochyear, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_epochday_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_epochday_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_epochday, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_epochsecond_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_epochsecond_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_epochsecond, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_meanmotiond1_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_meanmotiond1_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_meanmotiond1, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_meanmotiond2_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_meanmotiond2_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_meanmotiond2, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_dragterm_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_dragterm_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_dragterm, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_id_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_id_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_id, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_inclination_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_inclination_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_inclination, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_raan_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_raan_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_raan, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_eccentricity_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_eccentricity_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_eccentricity, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_argumentofperigee_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_argumentofperigee_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_argumentofperigee, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_meananomaly_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_meananomaly_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_meananomaly, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_meanmotion_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_meanmotion_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_meanmotion, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_numrevolutions_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_numrevolutions_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_numrevolutions, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_gps_twolineelementset_encode_malbinary(pf_gps_twolineelementset_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_catalogno_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_catalogno);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_classification != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_classification);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_idyear_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_idyear);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_idlaunchno_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_idlaunchno);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_idpiece != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_idpiece);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_epochyear_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_epochyear);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_epochday_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_epochday);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_epochsecond_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_epochsecond);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_meanmotiond1_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_meanmotiond1);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_meanmotiond2_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_meanmotiond2);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_dragterm_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_dragterm);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_id_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_id);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_inclination_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_inclination);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_raan_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_raan);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_eccentricity_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_eccentricity);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_argumentofperigee_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_argumentofperigee);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_meananomaly_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_meananomaly);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_meanmotion_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_meanmotion);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_numrevolutions_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_numrevolutions);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_gps_twolineelementset_decode_malbinary(pf_gps_twolineelementset_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_catalogno);
    if (rc < 0)
      return rc;
  }
  self->f_catalogno_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_classification);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_classification = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_idyear);
    if (rc < 0)
      return rc;
  }
  self->f_idyear_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_idlaunchno);
    if (rc < 0)
      return rc;
  }
  self->f_idlaunchno_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_idpiece);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_idpiece = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_epochyear);
    if (rc < 0)
      return rc;
  }
  self->f_epochyear_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_epochday);
    if (rc < 0)
      return rc;
  }
  self->f_epochday_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_epochsecond);
    if (rc < 0)
      return rc;
  }
  self->f_epochsecond_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_meanmotiond1);
    if (rc < 0)
      return rc;
  }
  self->f_meanmotiond1_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_meanmotiond2);
    if (rc < 0)
      return rc;
  }
  self->f_meanmotiond2_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_dragterm);
    if (rc < 0)
      return rc;
  }
  self->f_dragterm_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_id);
    if (rc < 0)
      return rc;
  }
  self->f_id_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_inclination);
    if (rc < 0)
      return rc;
  }
  self->f_inclination_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_raan);
    if (rc < 0)
      return rc;
  }
  self->f_raan_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_eccentricity);
    if (rc < 0)
      return rc;
  }
  self->f_eccentricity_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_argumentofperigee);
    if (rc < 0)
      return rc;
  }
  self->f_argumentofperigee_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_meananomaly);
    if (rc < 0)
      return rc;
  }
  self->f_meananomaly_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_meanmotion);
    if (rc < 0)
      return rc;
  }
  self->f_meanmotion_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_numrevolutions);
    if (rc < 0)
      return rc;
  }
  self->f_numrevolutions_is_present = presence_flag;
  return rc;
}

// destructor
void pf_gps_twolineelementset_destroy(pf_gps_twolineelementset_t ** self_p)
{
  if ((*self_p)->f_classification != NULL)
  {
    mal_string_destroy(& (*self_p)->f_classification);
  }
  if ((*self_p)->f_idpiece != NULL)
  {
    mal_string_destroy(& (*self_p)->f_idpiece);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_gps_twolineelementset_test(bool verbose)
{
  printf(" * PF:GPS:TwoLineElementSet: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
