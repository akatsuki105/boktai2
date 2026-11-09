	push {r4, r5, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r5, [r1]
	movs r1, #0xc0
	lsls r1, r1, #4
	ldr r2, _08193994 @ =0x00000F2C
	adds r3, r5, r2
	ldrh r2, [r3]
	movs r4, #0
	orrs r1, r2
	strh r1, [r3]
	movs r2, #0xe4
	lsls r2, r2, #4
	adds r1, r5, r2
	strb r4, [r1]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	ldr r2, _08193998 @ =0x00000546
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _081939A4
	ldr r1, _0819399C @ =0x00000E42
	adds r0, r5, r1
	ldrb r0, [r0]
	lsrs r0, r0, #1
	ldr r2, _081939A0 @ =0x00000E41
	adds r1, r5, r2
	strb r0, [r1]
	b _081939B0
	.align 2, 0
_08193994: .4byte 0x00000F2C
_08193998: .4byte 0x00000546
_0819399C: .4byte 0x00000E42
_081939A0: .4byte 0x00000E41
_081939A4:
	ldr r1, _081939B8 @ =0x00000E42
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _081939BC @ =0x00000E41
	adds r0, r5, r2
	strb r1, [r0]
_081939B0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081939B8: .4byte 0x00000E42
_081939BC: .4byte 0x00000E41
