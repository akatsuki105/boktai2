	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xee
	ldrh r0, [r5]
	cmp r0, #0
	bne _0807F972
	movs r2, #4
	ldr r1, _0807F9C8 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0807F9CC @ =0x00000302
	bl PlaySound_082406e0
	movs r0, #0xfd
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0807F972:
	ldr r0, _0807F9D0 @ =0x03002BE0
	ldr r2, [r0]
	adds r1, r2, #0
	adds r1, #0x90
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	adds r3, r4, #0
	adds r3, #0x5e
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	movs r7, #0x2e
	ldrsh r1, [r2, r7]
	adds r0, r0, r1
	adds r0, #0x96
	asrs r0, r0, #4
	strh r0, [r3]
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x1c
	bl MainSprite_AdvanceAnim
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0807F9C2
	adds r0, r4, #0
	adds r0, #0x56
	strb r6, [r0]
	ldr r1, _0807F9D4 @ =FUN_0807f9d8
	adds r0, r4, #0
	bl DarkDjangoEffect_SetState
_0807F9C2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F9C8: .4byte 0x030044BC
_0807F9CC: .4byte 0x00000302
_0807F9D0: .4byte 0x03002BE0
_0807F9D4: .4byte FUN_0807f9d8
