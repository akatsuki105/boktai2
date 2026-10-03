	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08093B60 @ =0x00002524
	adds r0, r4, r1
	ldr r2, _08093B64 @ =0x00003F9D
	adds r1, r4, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r4, r1
	bl MainSprite_AdvanceAnim
	ldr r1, _08093B68 @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	bge _08093B70
	ldr r2, _08093B6C @ =0x0000252C
	adds r0, r4, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08093B7A
	.align 2, 0
_08093B60: .4byte 0x00002524
_08093B64: .4byte 0x00003F9D
_08093B68: .4byte 0x000009EE
_08093B6C: .4byte 0x0000252C
_08093B70:
	ldr r1, _08093BA8 @ =0x0000252C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08093B7A:
	str r1, [r0]
	ldr r2, _08093BAC @ =0x000009EE
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _08093BA0
	ldr r1, _08093BB0 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e48
	adds r0, r4, #0
	bl FUN_08092744
_08093BA0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093BA8: .4byte 0x0000252C
_08093BAC: .4byte 0x000009EE
_08093BB0: .4byte 0x00003AEE
