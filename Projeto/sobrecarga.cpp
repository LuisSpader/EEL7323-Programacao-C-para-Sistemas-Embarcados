// #include <string.h>
// #include <stdlib.h>

// bool Data1EhMAIORqueData2(string data1, string data2)
// {
//   // Calendar obj_calendar;
//   tuple<int, int, int> buffer1, buffer2;         // tupla com os valores: dia, mes, ano
//   buffer1 = setStringToDate(data1); // recebendo os valores
//   buffer2 = setStringToDate(data2);
//   // get<0>: ano,  get<1>: mes,  get<2>: dia

//   if (get<2>(buffer1) > get<2>(buffer2))
//   {
//     return true; // se ano eh maior, data ja eh maior
//   }
//   else // se ano eh igual ou menor, iremos analisar qual dos dois eh
//   {
//     // ano = (get2), mes = (get1), dia = (get0)
//     if (get<2>(buffer1) == get<2>(buffer2)) // se ano eh igual, iremos analisar pelo mes e dia
//     {
//       if (get<1>(buffer1) > get<1>(buffer2)) // ano igual, mes maior
//       {
//         return true; // se mes eh maior, data ja eh maior
//       }
//       else // mes igual ou menor
//       {
//         if (get<1>(buffer1) == get<1>(buffer2)) // ano igual, mes igual
//         {
//           if (get<0>(buffer1) > get<0>(buffer2)) // ano igual, mes igual, dia maior
//           {
//             return true;
//           }
//           else
//           { // ano igual, mes igual, dia menor
//             return false;
//           }
//         }
//         else // ano igual, mes menor
//         {
//           return false; // se mes eh maior, data ja eh maior
//         }
//       }
//     }
//     else // se ano eh menor, data ja eh menor
//     {
//       return false;
//     }
//   }
// }

// bool Data1EhMENORqueData2(string data1, string data2)
// {
//   Calendar obj_calendar;
//   tuple<int, int, int> buffer1, buffer2;         // tupla com os valores: dia, mes, ano
//   buffer1 = obj_calendar.setStringToDate(data1); // recebendo os valores
//   buffer2 = obj_calendar.setStringToDate(data2);
//   // get<0>(buffer): ano,  get<1>(buffer): mes,  get<2>(buffer): dia

//   if (get<2>(buffer1) < get<2>(buffer2))
//   {
//     return true; // se ano eh menor, data ja eh menor
//   }
//   else // se ano eh igual ou maior, iremos analisar qual dos dois eh
//   {
//     // ano = (get2), mes = (get1), dia = (get0)
//     if (get<2>(buffer1) == get<2>(buffer2)) // se ano eh igual, iremos analisar pelo mes e dia
//     {
//       if (get<1>(buffer1) < get<1>(buffer2)) // ano igual, mes menor
//       {
//         return true; // se mes eh menor, data ja eh menor
//       }
//       else // mes igual ou maior
//       {
//         if (get<1>(buffer1) == get<1>(buffer2)) // ano igual, mes igual
//         {
//           if (get<0>(buffer1) < get<0>(buffer2)) // ano igual, mes igual, dia menor
//           {
//             return true;
//           }
//           else
//           { // ano igual, mes igual, dia maior
//             return false;
//           }
//         }
//         else // ano igual, mes maior
//         {
//           return false; // se mes eh maior, data ja eh maior
//         }
//       }
//     }
//     else // se ano eh maior, data ja eh maior
//     {
//       return false;
//     }
//   }
// }

// // -------------- Operadores para data --------------
// bool operator>(Calendar &c1, const Calendar &c2)
// {
//   return c1.Data1EhMAIORqueData2(c1.str_data.str(), c2.str_data.str());
// }

// bool operator<(Calendar &c1, const Calendar &c2)
// {
//   return c1.Data1EhMENORqueData2(c1.str_data.str(), c2.str_data.str());
// }

// // ================================================
// bool Clock::Hora1EhMAIORqueHora2(string hora1, string hora2)
// {
//   Clock obj_clock;
//   tuple<int, int, int> buffer1, buffer2;             // tupla com os valores: hora, min, seg
//   buffer1 = obj_clock.setStringToTime(hora1, false); // recebendo os valores
//   buffer2 = obj_clock.setStringToTime(hora2, false);
//   // get<0>: hora,  get<1>: minuto,  get<2>: segundo

//   if (get<0>(buffer1) > get<0>(buffer2))
//   {
//     return true; // se hora eh maior, data ja eh maior
//   }
//   else // se hora eh igual ou menor, iremos analisar qual dos dois eh
//   {
//     // hora = (get2), minuto = (get1), segundo = (get0)
//     if (get<0>(buffer1) == get<0>(buffer2)) // se hora eh igual, iremos analisar pelo minuto e segundo
//     {
//       if (get<1>(buffer1) > get<1>(buffer2)) // hora igual, minuto maior
//       {
//         return true; // se minuto eh maior, data ja eh maior
//       }
//       else // minuto igual ou menor
//       {
//         if (get<1>(buffer1) == get<1>(buffer2)) // hora igual, minuto igual
//         {
//           if (get<2>(buffer1) >= get<2>(buffer2)) // hora igual, minuto igual, segundo maior ou igual
//           {
//             return true;
//           }
//           else
//           { // hora igual, minuto igual, segundo menor
//             return false;
//           }
//         }
//         else // hora igual, minuto menor
//         {
//           return false; // se minuto eh maior, data ja eh maior
//         }
//       }
//     }
//     else // se hora eh menor, data ja eh menor
//     {
//       return false;
//     }
//   }
// }

// bool Clock::Hora1EhMENORqueHora2(string hora1, string hora2)
// {
//   Clock obj_clock;
//   tuple<int, int, int> buffer1, buffer2;             // tupla com os valores: segundo, minuto, hora
//   buffer1 = obj_clock.setStringToTime(hora1, false); // recebendo os valores
//   buffer2 = obj_clock.setStringToTime(hora2, false);
//   // get<0>: hora,  get<1>: minuto,  get<2>: segundo

//   if (get<0>(buffer1) < get<0>(buffer2))
//   {
//     return true; // se hora eh menor, data ja eh menor
//   }
//   else // se hora eh igual ou maior, iremos analisar qual dos dois eh
//   {
//     // hora = (get2), minuto = (get1), segundo = (get0)
//     if (get<0>(buffer1) == get<0>(buffer2)) // se hora eh igual, iremos analisar pelo minuto e segundo
//     {
//       if (get<1>(buffer1) < get<1>(buffer2)) // hora igual, minuto menor
//       {
//         return true; // se minuto eh menor, data ja eh menor
//       }
//       else // minuto igual ou maior
//       {
//         if (get<1>(buffer1) == get<1>(buffer2)) // hora igual, minuto igual
//         {
//           if (get<2>(buffer1) <= get<2>(buffer2)) // hora igual, minuto igual, segundo menor ou igual
//           {
//             return true;
//           }
//           else
//           { // hora igual, minuto igual, segundo maior
//             return false;
//           }
//         }
//         else // hora igual, minuto maior
//         {
//           return false; // se minuto eh maior, data ja eh maior
//         }
//       }
//     }
//     else // se hora eh maior, data ja eh maior
//     {
//       return false;
//     }
//   }
// }

// // -------------- Operadores para hora --------------
// bool operator>=(Clock &c1, const Clock &c2)
// {
//   return c1.Hora1EhMAIORqueHora2(c1.str_hora.str(), c2.str_hora.str());
// }

// bool operator<=(Clock &c1, const Clock &c2)
// {
//   return c1.Hora1EhMENORqueHora2(c1.str_hora.str(), c2.str_hora.str());
// }
