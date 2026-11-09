	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r4, r0, #3
	movs r0, #7
	ands r4, r0
	mov r2, sp
	adds r2, #5
	adds r0, r5, #0
	add r1, sp, #4
	bl Enemy_SetAnimFacing
	cmp r4, #7
	bls _0815C178
	b _0815C4B0
_0815C178:
	lsls r0, r4, #2
	ldr r1, _0815C184 @ =_0815C188
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815C184: .4byte _0815C188
_0815C188: @ jump table
	.4byte _0815C1A8 @ case 0
	.4byte _0815C1A8 @ case 1
	.4byte _0815C22C @ case 2
	.4byte _0815C2E8 @ case 3
	.4byte _0815C2E8 @ case 4
	.4byte _0815C36C @ case 5
	.4byte _0815C3AA @ case 6
	.4byte _0815C42A @ case 7
_0815C1A8:
	ldr r1, _0815C1CC @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C1D0 @ =0x0000025D
	adds r0, r5, r1
	ldrb r6, [r0]
	cmp r6, #0
	bne _0815C1D8
	ldr r1, _0815C1D4 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	adds r3, r4, #0
	str r6, [sp]
	b _0815C44C
	.align 2, 0
_0815C1CC: .4byte 0x000004D4
_0815C1D0: .4byte 0x0000025D
_0815C1D4: .4byte 0x000004B7
_0815C1D8:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, r2, r4
	ldr r1, _0815C224 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0815C228 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0815C202
	ldrb r0, [r6]
	cmp r0, #0
	bne _0815C202
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0815C202
	b _0815C4B0
_0815C202:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r7, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	b _0815C4AA
	.align 2, 0
_0815C224: .4byte 0x000004B7
_0815C228: .4byte 0x0000046E
_0815C22C:
	add r0, sp, #4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C2B8
	ldr r1, _0815C258 @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C25C @ =0x0000025D
	adds r0, r5, r1
	ldrb r6, [r0]
	cmp r6, #0
	bne _0815C264
	ldr r1, _0815C260 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	adds r3, r4, #0
	str r6, [sp]
	b _0815C44C
	.align 2, 0
_0815C258: .4byte 0x000004D4
_0815C25C: .4byte 0x0000025D
_0815C260: .4byte 0x000004B7
_0815C264:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, r2, r4
	ldr r1, _0815C2B0 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0815C2B4 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0815C28E
	ldrb r0, [r6]
	cmp r0, #0
	bne _0815C28E
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0815C28E
	b _0815C4B0
_0815C28E:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r7, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	b _0815C4AA
	.align 2, 0
_0815C2B0: .4byte 0x000004B7
_0815C2B4: .4byte 0x0000046E
_0815C2B8:
	ldr r1, _0815C2DC @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r3, r4, #1
	ldr r1, _0815C2E0 @ =0x0000025D
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	bne _0815C318
	ldr r1, _0815C2E4 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r4, [sp]
	b _0815C44C
	.align 2, 0
_0815C2DC: .4byte 0x000004D4
_0815C2E0: .4byte 0x0000025D
_0815C2E4: .4byte 0x000004B7
_0815C2E8:
	ldr r1, _0815C30C @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r3, r4, #1
	ldr r1, _0815C310 @ =0x0000025D
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	bne _0815C318
	ldr r1, _0815C314 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r4, [sp]
	b _0815C44C
	.align 2, 0
_0815C30C: .4byte 0x000004D4
_0815C310: .4byte 0x0000025D
_0815C314: .4byte 0x000004B7
_0815C318:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, r2, r3
	ldr r1, _0815C364 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0815C368 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0815C342
	ldrb r0, [r6]
	cmp r0, #0
	bne _0815C342
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0815C342
	b _0815C4B0
_0815C342:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	b _0815C4AC
	.align 2, 0
_0815C364: .4byte 0x000004B7
_0815C368: .4byte 0x0000046E
_0815C36C:
	ldr r1, _0815C394 @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C398 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C3A0
	ldr r1, _0815C39C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #1
	str r3, [sp]
	movs r3, #4
	b _0815C44C
	.align 2, 0
_0815C394: .4byte 0x000004D4
_0815C398: .4byte 0x0000025D
_0815C39C: .4byte 0x000004B7
_0815C3A0:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, #4
	b _0815C470
_0815C3AA:
	add r0, sp, #4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C3EE
	ldr r1, _0815C3D8 @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C3DC @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C3E4
	ldr r1, _0815C3E0 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #1
	str r3, [sp]
	movs r3, #2
	b _0815C44C
	.align 2, 0
_0815C3D8: .4byte 0x000004D4
_0815C3DC: .4byte 0x0000025D
_0815C3E0: .4byte 0x000004B7
_0815C3E4:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, #2
	b _0815C470
_0815C3EE:
	ldr r1, _0815C414 @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C418 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C420
	ldr r1, _0815C41C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #1
	str r3, [sp]
	movs r3, #3
	b _0815C44C
	.align 2, 0
_0815C414: .4byte 0x000004D4
_0815C418: .4byte 0x0000025D
_0815C41C: .4byte 0x000004B7
_0815C420:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, #3
	b _0815C470
_0815C42A:
	ldr r1, _0815C458 @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C45C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C468
	ldr r1, _0815C460 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #1
	str r3, [sp]
_0815C44C:
	bl AuxAnim_SetAnim
	ldr r0, _0815C464 @ =0x0000046E
	adds r6, r5, r0
	b _0815C4AC
	.align 2, 0
_0815C458: .4byte 0x000004D4
_0815C45C: .4byte 0x0000025D
_0815C460: .4byte 0x000004B7
_0815C464: .4byte 0x0000046E
_0815C468:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, #1
_0815C470:
	ldr r1, _0815C4B8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0815C4BC @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0815C490
	ldrb r0, [r6]
	cmp r0, #0
	bne _0815C490
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0815C4B0
_0815C490:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r4, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r7, #8]
	orrs r0, r4
_0815C4AA:
	str r0, [r7, #8]
_0815C4AC:
	movs r0, #0
	strb r0, [r6]
_0815C4B0:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815C4B8: .4byte 0x000004B7
_0815C4BC: .4byte 0x0000046E
