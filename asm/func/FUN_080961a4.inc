	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080961CC @ =0x000009EE
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080961EC
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080961D4
	ldr r2, _080961D0 @ =0x00001BE6
	adds r1, r4, r2
	b _080961FA
	.align 2, 0
_080961CC: .4byte 0x000009EE
_080961D0: .4byte 0x00001BE6
_080961D4:
	ldrh r1, [r2]
	movs r0, #0x10
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x68
	subs r1, r1, r0
	ldr r2, _080961E8 @ =0x00001BE6
	adds r0, r4, r2
	strh r1, [r0]
	b _080961FE
	.align 2, 0
_080961E8: .4byte 0x00001BE6
_080961EC:
	ldr r1, _08096204 @ =FUN_08095ae8
	adds r0, r4, #0
	movs r2, #0
	bl EntityCC28_SetState
	ldr r0, _08096208 @ =0x00001BE6
	adds r1, r4, r0
_080961FA:
	movs r0, #0x68
	strh r0, [r1]
_080961FE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096204: .4byte FUN_08095ae8
_08096208: .4byte 0x00001BE6
