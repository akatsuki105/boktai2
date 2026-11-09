	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r2, _08179FB0 @ =0x00000546
	adds r1, r0, r2
	ldrh r1, [r1]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	blt _08179FD8
	ldr r0, _08179FB4 @ =0x00000F98
	adds r1, r3, r0
	movs r0, #0x28
	strh r0, [r1]
	ldr r2, _08179FB8 @ =0x00000F9A
	adds r1, r3, r2
	movs r0, #0xdc
	strh r0, [r1]
	ldr r0, _08179FBC @ =0x00000F9C
	adds r1, r3, r0
	movs r0, #0x1e
	strh r0, [r1]
	adds r2, #6
	adds r1, r3, r2
	movs r0, #8
	strh r0, [r1]
	ldr r0, _08179FC0 @ =0x00000F9E
	adds r1, r3, r0
	movs r0, #0x40
	strh r0, [r1]
	adds r2, #2
	adds r1, r3, r2
	movs r0, #0xa
	strh r0, [r1]
	ldr r2, _08179FC4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08179FC8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08179FCC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x64
	ldr r2, _08179FD0 @ =0x00000FA4
	adds r1, r3, r2
	strh r0, [r1]
	ldr r0, _08179FD4 @ =0x00000FA6
	adds r1, r3, r0
	movs r0, #1
	b _0817A030
	.align 2, 0
_08179FB0: .4byte 0x00000546
_08179FB4: .4byte 0x00000F98
_08179FB8: .4byte 0x00000F9A
_08179FBC: .4byte 0x00000F9C
_08179FC0: .4byte 0x00000F9E
_08179FC4: .4byte 0x030046B8
_08179FC8: .4byte 0x000003FF
_08179FCC: .4byte 0x0203B400
_08179FD0: .4byte 0x00000FA4
_08179FD4: .4byte 0x00000FA6
_08179FD8:
	ldr r1, _0817A038 @ =0x00000F98
	adds r0, r3, r1
	movs r2, #0x50
	strh r2, [r0]
	ldr r0, _0817A03C @ =0x00000F9A
	adds r1, r3, r0
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r1, _0817A040 @ =0x00000F9C
	adds r0, r3, r1
	strh r2, [r0]
	movs r2, #0xfa
	lsls r2, r2, #4
	adds r1, r3, r2
	movs r0, #0x28
	strh r0, [r1]
	ldr r0, _0817A044 @ =0x00000F9E
	adds r1, r3, r0
	movs r0, #0x64
	strh r0, [r1]
	adds r2, #2
	adds r1, r3, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r2, _0817A048 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0817A04C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0817A050 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0xc8
	ldr r2, _0817A054 @ =0x00000FA4
	adds r1, r3, r2
	strh r0, [r1]
	ldr r0, _0817A058 @ =0x00000FA6
	adds r1, r3, r0
	movs r0, #3
_0817A030:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0817A038: .4byte 0x00000F98
_0817A03C: .4byte 0x00000F9A
_0817A040: .4byte 0x00000F9C
_0817A044: .4byte 0x00000F9E
_0817A048: .4byte 0x030046B8
_0817A04C: .4byte 0x000003FF
_0817A050: .4byte 0x0203B400
_0817A054: .4byte 0x00000FA4
_0817A058: .4byte 0x00000FA6
