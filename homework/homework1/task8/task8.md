## The Patriot Missile Failure

During the gulf war an American patriot missile failed to intercept an incoming Iraqi Scud missile. The failure was caused by truncation errors in the system's clock. The system's clock measured time since boot in tenths of a second. This value was multiplied by the binary expansion of 1/10 to yield the number of seconds since boot. Because this calculation was limited to 24 bits of precision, after 100 hours the internal clock was off by more than 0.34 seconds.

## The Explosion of the Ariane 5

In 1996 an unmanned Ariane 5 rocket exploed forty seconds after takeoff. The cause was determined to be due to conversion from a 64 bit floating point number to a 16 bit integer. Specifically, when converted the floating point number exceeded the largest number storable by a 16 bit integer. Consequently, the conversion failed and the rocket triggered its self-destruct.

## The Sinking of the Sleipner A Offshore Platform

In 1991 a Sleipner A offshore platform sank off the shore of Norway. The failure of the platform was due to the failure of a concrete cell wall. The failure of the cell wall is attributed to an error in the finite element program used to model the wall. The software underestimated the shear stresses in the wall by 47%. This meant that the wall was not nearly thick enough to cope with the high pressures at depth.