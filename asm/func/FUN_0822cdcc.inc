	push {r4, r5, lr}
	adds r4, r1, #0
	ldr r5, [sp, #0xc]
	cmp r0, #0
	bne _0822CE00
	ldr r1, _0822CDF0 @ =0x03003F90
	lsls r0, r4, #8
	orrs r0, r3
	strh r0, [r1]
	ldr r1, _0822CDF4 @ =0x04000040
	strh r0, [r1]
	ldr r1, _0822CDF8 @ =0x03003F9C
	lsls r0, r2, #8
	orrs r0, r5
	strh r0, [r1]
	ldr r1, _0822CDFC @ =0x04000044
	b _0822CE16
	.align 2, 0
_0822CDF0: .4byte 0x03003F90
_0822CDF4: .4byte 0x04000040
_0822CDF8: .4byte 0x03003F9C
_0822CDFC: .4byte 0x04000044
_0822CE00:
	ldr r1, _0822CE20 @ =0x03003FA8
	lsls r0, r4, #8
	orrs r0, r3
	strh r0, [r1]
	ldr r1, _0822CE24 @ =0x04000042
	strh r0, [r1]
	ldr r1, _0822CE28 @ =0x03003F98
	lsls r0, r2, #8
	orrs r0, r5
	strh r0, [r1]
	ldr r1, _0822CE2C @ =0x04000046
_0822CE16:
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0822CE20: .4byte 0x03003FA8
_0822CE24: .4byte 0x04000042
_0822CE28: .4byte 0x03003F98
_0822CE2C: .4byte 0x04000046
