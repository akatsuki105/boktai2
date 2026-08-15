	push {r4, r5, r6, lr}
	ldr r2, _082475B4 @ =0x030026C0
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r4, #1
	orrs r0, r4
	str r0, [r2]
	ldr r0, _082475B8 @ =0x030026B4
	movs r2, #0
	str r2, [r0]
	ldr r0, _082475BC @ =0x030026B8
	str r2, [r0]
	ldr r0, _082475C0 @ =0x030057B8
	str r2, [r0]
	ldr r1, _082475C4 @ =0x030057CC
	ldr r0, _082475C8 @ =0x00003128
	str r0, [r1]
	ldr r0, _082475CC @ =0x030057C0
	str r4, [r0]
	ldr r1, _082475D0 @ =0x030057B0
	movs r0, #0xff
	str r0, [r1]
	ldr r1, _082475D4 @ =0x030057C4
	movs r0, #4
	str r0, [r1]
	ldr r1, _082475D8 @ =0x030057C8
	subs r0, #5
	str r0, [r1]
	ldr r5, _082475DC @ =0x04000208
	strh r2, [r5]
	ldr r3, _082475E0 @ =0x04000200
	ldrh r6, [r3]
	strh r2, [r3]
	ldr r0, _082475E4 @ =0x0400010C
	strh r2, [r0]
	ldr r1, _082475E8 @ =0x0400010E
	movs r0, #0xc0
	strh r0, [r1]
	ldr r1, _082475EC @ =0x03002CB0
	ldr r0, _082475F0 @ =Sensor_Tick
	str r0, [r1, #8]
	ldr r1, _082475F4 @ =0x030057B4
	ldr r0, _082475F8 @ =ROM_GPIODATA
	ldrh r0, [r0]
	str r0, [r1]
	ldr r1, _082475FC @ =ROM_GPIODIR
	movs r0, #7
	strh r0, [r1]
	ldr r0, _08247600 @ =ROM_GPIOCNT
	strh r4, [r0]
	movs r0, #0x40
	orrs r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	strh r0, [r3]
	strh r4, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082475B4: .4byte 0x030026C0
_082475B8: .4byte 0x030026B4
_082475BC: .4byte 0x030026B8
_082475C0: .4byte 0x030057B8
_082475C4: .4byte 0x030057CC
_082475C8: .4byte 0x00003128
_082475CC: .4byte 0x030057C0
_082475D0: .4byte 0x030057B0
_082475D4: .4byte 0x030057C4
_082475D8: .4byte 0x030057C8
_082475DC: .4byte 0x04000208
_082475E0: .4byte 0x04000200
_082475E4: .4byte 0x0400010C
_082475E8: .4byte 0x0400010E
_082475EC: .4byte 0x03002CB0
_082475F0: .4byte Sensor_Tick
_082475F4: .4byte 0x030057B4
_082475F8: .4byte ROM_GPIODATA
_082475FC: .4byte ROM_GPIODIR
_08247600: .4byte ROM_GPIOCNT
