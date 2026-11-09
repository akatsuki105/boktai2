	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	ldr r2, _0810C5BC @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810C5C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810C5C2
	.align 2, 0
_0810C5BC: .4byte 0x0000046D
_0810C5C0:
	movs r0, #0
_0810C5C2:
	cmp r0, #0
	beq _0810C5DE
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r7, r3
	bl ParticleShadow_Show
	adds r0, r7, #0
	movs r1, #0xd
	bl Enemy_PlayAnim
	ldr r0, _0810C85C @ =0x000003AE
	bl PlaySound_082406e0
_0810C5DE:
	ldr r1, _0810C860 @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810C5EA
	b _0810C84A
_0810C5EA:
	adds r3, r7, #0
	adds r3, #0xde
	ldrh r2, [r3]
	ldr r1, _0810C864 @ =0x0000FFFB
	adds r0, r1, #0
	ands r0, r2
	movs r2, #0
	mov sb, r2
	movs r6, #0
	strh r0, [r3]
	movs r0, #0x97
	lsls r0, r0, #1
	adds r3, r7, r0
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r2, _0810C868 @ =0x0000065E
	adds r3, r4, r2
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r3, _0810C86C @ =0x000006AE
	adds r2, r4, r3
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r7, r0
	ldr r4, _0810C870 @ =0xFFFFF7FF
	ldrh r0, [r5]
	ands r4, r0
	strh r4, [r5]
	ldrb r1, [r7, #5]
	str r1, [sp]
	movs r2, #0x80
	lsls r2, r2, #7
	ands r4, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	rsbs r4, r4, #0
	asrs r4, r4, #0x1f
	ands r4, r2
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r2, _0810C874 @ =0x0000055C
	adds r0, r7, r2
	ldr r0, [r0]
	str r0, [r1]
	adds r3, #4
	adds r1, r7, r3
	adds r2, #4
	adds r0, r7, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r3, _0810C878 @ =0x00000564
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r7, #5]
	ldr r1, _0810C87C @ =0x00000565
	adds r0, r7, r1
	ldrb r0, [r0]
	subs r2, #0xf8
	adds r2, r7, r2
	str r2, [sp, #4]
	strb r0, [r2]
	adds r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	subs r1, #0xfc
	adds r1, r7, r1
	str r1, [sp, #8]
	strb r0, [r1]
	ldr r2, _0810C880 @ =0x00000567
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r3, #0xfc
	adds r3, r7, r3
	str r3, [sp, #0xc]
	strb r0, [r3]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x10]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, [sp, #0x10]
	str r0, [r2]
	ldr r3, _0810C884 @ =0x0000056C
	adds r0, r7, r3
	ldrb r0, [r0]
	subs r1, #0x15
	adds r1, r7, r1
	str r1, [sp, #0x14]
	strb r0, [r1]
	ldr r2, _0810C888 @ =0x00000572
	adds r0, r7, r2
	ldrh r1, [r0]
	subs r3, #0xf8
	adds r0, r7, r3
	strh r1, [r0]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r3, #0x95
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r1, [r0]
	subs r2, #0x3a
	adds r0, r7, r2
	strh r1, [r0]
	subs r3, #0xd2
	adds r0, r7, r3
	strh r6, [r0]
	ldr r1, _0810C88C @ =0x00000222
	adds r0, r7, r1
	strh r6, [r0]
	strh r6, [r5]
	ldr r2, _0810C890 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x18]
	mov r3, sb
	strb r3, [r2]
	ldr r0, _0810C894 @ =0x0000046C
	adds r0, r0, r7
	mov sl, r0
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0810C898 @ =0x0000046D
	adds r2, r2, r7
	mov r8, r2
	strb r1, [r2]
	ldr r3, _0810C860 @ =0x0000046E
	adds r0, r7, r3
	mov r2, sb
	strb r2, [r0]
	ldr r3, _0810C89C @ =0x0000024E
	adds r0, r7, r3
	strh r6, [r0]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	ldr r3, _0810C8A0 @ =0x00000544
	adds r0, r7, r3
	strh r6, [r0]
	ldr r2, _0810C8A4 @ =0x00000466
	adds r0, r7, r2
	strh r6, [r0]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r0, r7, r3
	str r6, [r0]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	str r6, [r0]
	adds r3, #9
	adds r0, r7, r3
	mov r2, sb
	strb r2, [r0]
	adds r3, #0x3f
	adds r0, r7, r3
	strb r2, [r0]
	ldr r2, _0810C8A8 @ =0x00000482
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0x93
	lsls r3, r3, #3
	adds r0, r7, r3
	str r6, [r0]
	ldr r1, _0810C8AC @ =0x0000049C
	adds r0, r7, r1
	str r6, [r0]
	adds r2, #0x1e
	adds r0, r7, r2
	str r6, [r0]
	subs r3, #0xc
	adds r0, r7, r3
	mov r1, sb
	strb r1, [r0]
	adds r2, #0x1e
	adds r0, r7, r2
	strh r6, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _0810C8B0 @ =0x0000048E
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	subs r3, #0x35
	adds r0, r7, r3
	movs r1, #8
	bl ClearMemory
	ldr r1, _0810C8B4 @ =0x00000464
	adds r0, r7, r1
	strh r6, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r6, [r0]
	ldr r3, _0810C8B8 @ =0x00000462
	adds r0, r7, r3
	strh r6, [r0]
	ldr r1, _0810C8BC @ =0x08251FCC
	adds r0, r7, #0
	ldr r2, _0810C8C0 @ =0x00000982
	bl Enemy_ClearPendingState
	movs r1, #0xa8
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	ldr r3, _0810C8C4 @ =0x00000541
	adds r0, r7, r3
	strb r2, [r0]
	ldr r0, _0810C8C8 @ =0x00000542
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r7, r1
	str r6, [r0]
	ldr r2, _0810C8CC @ =0x0000054C
	adds r0, r7, r2
	mov r3, sb
	strb r3, [r0]
	adds r1, #5
	adds r0, r7, r1
	strb r3, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _0810C8D0 @ =0x0000054F
	adds r0, r7, r3
	mov r1, sb
	strb r1, [r0]
	adds r0, r7, #0
	bl EnemyManager_TryEndPaletteFade
	ldrh r0, [r5]
	orrs r4, r0
	strh r4, [r5]
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r7, #5]
	adds r0, r7, #0
	bl Skeleton_OnReset
	ldrh r0, [r5]
	movs r3, #0x80
	lsls r3, r3, #7
	ands r0, r3
	cmp r0, #0
	beq _0810C84A
	movs r0, #2
	ldr r1, [sp, #4]
	strb r0, [r1]
	mov r3, sb
	ldr r2, [sp, #8]
	strb r3, [r2]
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	ldr r2, _0810C8D4 @ =0x00000484
	adds r0, r7, r2
	str r6, [r0]
	movs r0, #1
	mov r3, sl
	strb r0, [r3]
	ldr r1, _0810C8D8 @ =Enemy_ClearStateBegun
	movs r0, #0x10
	movs r3, #1
	mov r2, r8
	strb r3, [r2]
	mov r3, sb
	ldr r2, [sp, #0x18]
	strb r3, [r2]
	ldr r2, [sp, #0x14]
	strb r0, [r2]
	ldr r3, [sp, #0x10]
	str r1, [r3]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r6, [r0]
	adds r0, r7, #0
	adds r0, #0x48
	movs r1, #1
	bl MsgQueue_EndWait
_0810C84A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810C85C: .4byte 0x000003AE
_0810C860: .4byte 0x0000046E
_0810C864: .4byte 0x0000FFFB
_0810C868: .4byte 0x0000065E
_0810C86C: .4byte 0x000006AE
_0810C870: .4byte 0xFFFFF7FF
_0810C874: .4byte 0x0000055C
_0810C878: .4byte 0x00000564
_0810C87C: .4byte 0x00000565
_0810C880: .4byte 0x00000567
_0810C884: .4byte 0x0000056C
_0810C888: .4byte 0x00000572
_0810C88C: .4byte 0x00000222
_0810C890: .4byte 0x0000046B
_0810C894: .4byte 0x0000046C
_0810C898: .4byte 0x0000046D
_0810C89C: .4byte 0x0000024E
_0810C8A0: .4byte 0x00000544
_0810C8A4: .4byte 0x00000466
_0810C8A8: .4byte 0x00000482
_0810C8AC: .4byte 0x0000049C
_0810C8B0: .4byte 0x0000048E
_0810C8B4: .4byte 0x00000464
_0810C8B8: .4byte 0x00000462
_0810C8BC: .4byte 0x08251FCC
_0810C8C0: .4byte 0x00000982
_0810C8C4: .4byte 0x00000541
_0810C8C8: .4byte 0x00000542
_0810C8CC: .4byte 0x0000054C
_0810C8D0: .4byte 0x0000054F
_0810C8D4: .4byte 0x00000484
_0810C8D8: .4byte Enemy_ClearStateBegun
