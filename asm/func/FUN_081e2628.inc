	push {r4, r5, r6, lr}
	movs r1, #0xaf
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0
	strh r1, [r2]
	ldr r3, _081E2730 @ =0x00000AF2
	adds r2, r0, r3
	movs r1, #1
	strh r1, [r2]
	ldr r6, _081E2734 @ =0x00000AF4
	adds r2, r0, r6
	movs r1, #2
	strh r1, [r2]
	ldr r1, _081E2738 @ =0x00000AF6
	adds r2, r0, r1
	movs r1, #3
	strh r1, [r2]
	ldr r2, _081E273C @ =0x00000AF8
	adds r1, r0, r2
	movs r5, #4
	strh r5, [r1]
	adds r3, #8
	adds r1, r0, r3
	movs r4, #5
	strh r4, [r1]
	adds r6, #8
	adds r2, r0, r6
	movs r1, #6
	strh r1, [r2]
	ldr r1, _081E2740 @ =0x00000AFE
	adds r2, r0, r1
	movs r1, #7
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #8
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #9
	strh r1, [r2]
	ldr r1, _081E2744 @ =0x00000B04
	adds r2, r0, r1
	movs r1, #0xb
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0xc
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0xd
	strh r1, [r2]
	ldr r1, _081E2748 @ =0x00000B0A
	adds r2, r0, r1
	movs r1, #0xe
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0xf
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0x10
	strh r1, [r2]
	movs r1, #0xb1
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0x11
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0x12
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0x13
	strh r1, [r2]
	ldr r1, _081E274C @ =0x00000B16
	adds r2, r0, r1
	movs r1, #0x14
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0x16
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0x17
	strh r1, [r2]
	ldr r1, _081E2750 @ =0x00000B1C
	adds r2, r0, r1
	movs r1, #0x18
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0x19
	strh r1, [r2]
	adds r6, #0x14
	adds r2, r0, r6
	movs r1, #0x15
	strh r1, [r2]
	movs r1, #0xb2
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0x3c
	strh r1, [r2]
	ldr r2, _081E2754 @ =0x00000B22
	adds r1, r0, r2
	movs r2, #0x41
	strh r2, [r1]
	adds r3, #6
	adds r1, r0, r3
	strh r2, [r1]
	subs r6, #8
	adds r3, r0, r6
	strh r2, [r3]
	adds r6, #2
	adds r1, r0, r6
	strh r2, [r1]
	ldr r2, _081E2758 @ =0x00000B2A
	adds r1, r0, r2
	strh r5, [r1]
	adds r6, #4
	adds r0, r0, r6
	strh r4, [r0]
	movs r0, #0x40
	strh r0, [r3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E2730: .4byte 0x00000AF2
_081E2734: .4byte 0x00000AF4
_081E2738: .4byte 0x00000AF6
_081E273C: .4byte 0x00000AF8
_081E2740: .4byte 0x00000AFE
_081E2744: .4byte 0x00000B04
_081E2748: .4byte 0x00000B0A
_081E274C: .4byte 0x00000B16
_081E2750: .4byte 0x00000B1C
_081E2754: .4byte 0x00000B22
_081E2758: .4byte 0x00000B2A
