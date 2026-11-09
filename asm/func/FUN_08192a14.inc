	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r2, _08192A6C @ =0x00000546
	adds r1, r0, r2
	ldrh r1, [r1]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	blt _08192A88
	movs r0, #0xd5
	lsls r0, r0, #4
	adds r1, r3, r0
	movs r0, #0x28
	strh r0, [r1]
	ldr r2, _08192A70 @ =0x00000D52
	adds r1, r3, r2
	movs r0, #0x64
	strh r0, [r1]
	ldr r2, _08192A74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08192A78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08192A7C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x50
	ldr r2, _08192A80 @ =0x00000D54
	adds r1, r3, r2
	strh r0, [r1]
	ldr r0, _08192A84 @ =0x00000D56
	adds r1, r3, r0
	movs r0, #1
	b _08192AC0
	.align 2, 0
_08192A6C: .4byte 0x00000546
_08192A70: .4byte 0x00000D52
_08192A74: .4byte 0x030046B8
_08192A78: .4byte 0x000003FF
_08192A7C: .4byte 0x0203B400
_08192A80: .4byte 0x00000D54
_08192A84: .4byte 0x00000D56
_08192A88:
	movs r2, #0xd5
	lsls r2, r2, #4
	adds r1, r3, r2
	movs r0, #0x50
	strh r0, [r1]
	ldr r0, _08192AC8 @ =0x00000D52
	adds r1, r3, r0
	movs r0, #0xc8
	strh r0, [r1]
	ldr r2, _08192ACC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08192AD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08192AD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0xa0
	ldr r2, _08192AD8 @ =0x00000D54
	adds r1, r3, r2
	strh r0, [r1]
	ldr r0, _08192ADC @ =0x00000D56
	adds r1, r3, r0
	movs r0, #3
_08192AC0:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08192AC8: .4byte 0x00000D52
_08192ACC: .4byte 0x030046B8
_08192AD0: .4byte 0x000003FF
_08192AD4: .4byte 0x0203B400
_08192AD8: .4byte 0x00000D54
_08192ADC: .4byte 0x00000D56
