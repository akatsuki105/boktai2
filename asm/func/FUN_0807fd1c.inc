	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xee
	ldrh r0, [r4]
	cmp r0, #0
	bne _0807FD38
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0807FD38:
	ldr r4, _0807FD98 @ =0x03002BE0
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0x90
	ldr r1, [r2]
	movs r6, #1
	orrs r1, r6
	str r1, [r2]
	ldr r1, _0807FD9C @ =0x0000060C
	adds r0, r0, r1
	bl ParticleShadow_Show
	adds r0, r5, #0
	adds r0, #0x3c
	adds r1, r5, #0
	adds r1, #0x1c
	bl MainSprite_AdvanceAnim
	cmp r0, #0
	beq _0807FD92
	ldr r0, [r4]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0807FDA0 @ =0x000002E6
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0807FDA4 @ =0x000002E7
	adds r0, r0, r1
	strb r6, [r0]
	ldr r1, _0807FDA8 @ =FUN_0807fdac
	adds r0, r5, #0
	bl DjangoBerserk_SetState
_0807FD92:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807FD98: .4byte 0x03002BE0
_0807FD9C: .4byte 0x0000060C
_0807FDA0: .4byte 0x000002E6
_0807FDA4: .4byte 0x000002E7
_0807FDA8: .4byte FUN_0807fdac
