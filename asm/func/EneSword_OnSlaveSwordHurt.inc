	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	movs r2, #0x81
	lsls r2, r2, #1
	adds r4, r5, r2
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bgt _08198308
	b _0819857C
_08198308:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _08198316
	b _0819857C
_08198316:
	adds r0, r5, #0
	adds r0, #0xdc
	ldrh r0, [r0]
	cmp r0, #0
	beq _08198322
	b _0819857C
_08198322:
	adds r0, r6, #0
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
	adds r0, r6, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r2]
	cmp r0, #0
	bne _081983BC
	ldrh r0, [r7, #0x3e]
	cmp r0, #0
	beq _081983BC
	movs r3, #0x90
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #8
	strh r0, [r1]
	ldr r0, _081983A8 @ =FUN_081999f4
	str r0, [r2]
	ldr r0, [r5, #0xc]
	ldr r1, _081983AC @ =0x00000CC8
	add r1, r8
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	ldrh r1, [r4]
	ldrh r0, [r7, #0x3e]
	subs r1, r1, r0
	strh r1, [r4]
	ldr r0, _081983B0 @ =0x00000C8A
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrh r3, [r6, #0x3e]
	adds r0, r0, r3
	strh r0, [r6, #0x3e]
	lsls r1, r1, #0x10
	cmp r1, #0
	bgt _081983BC
	movs r0, #1
	movs r1, #5
	movs r3, #0x8b
	lsls r3, r3, #1
	adds r2, r5, r3
	strb r0, [r2]
	adds r3, #1
	adds r2, r5, r3
	strb r1, [r2]
	ldr r1, _081983B4 @ =0x00000111
	adds r2, r5, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, _081983B8 @ =FUN_08199da0
	str r0, [r1]
	b _0819856A
	.align 2, 0
_081983A8: .4byte FUN_081999f4
_081983AC: .4byte 0x00000CC8
_081983B0: .4byte 0x00000C8A
_081983B4: .4byte 0x00000111
_081983B8: .4byte FUN_08199da0
_081983BC:
	ldr r3, _08198430 @ =0x00000117
	adds r0, r5, r3
	ldrb r2, [r0]
	adds r4, r0, #0
	cmp r2, #2
	bne _081983D6
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _08198434 @ =FUN_08198d0c
	cmp r1, r0
	bne _08198410
_081983D6:
	cmp r2, #3
	bne _081983EE
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	ldr r0, _08198438 @ =FUN_08199064
	cmp r1, r0
	beq _08198410
	ldr r0, _0819843C @ =FUN_08199094
	cmp r1, r0
	beq _08198410
_081983EE:
	cmp r2, #4
	beq _081983F4
	b _08198564
_081983F4:
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _08198440 @ =FUN_081994e8
	cmp r1, r0
	beq _08198410
	ldr r0, _08198444 @ =FUN_08199568
	cmp r1, r0
	beq _08198410
	ldr r0, _08198448 @ =FUN_081996f0
	cmp r1, r0
	beq _08198410
	b _08198564
_08198410:
	adds r0, r5, #0
	bl FUN_08199a3c
	ldrb r0, [r4]
	cmp r0, #2
	bne _0819844C
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0x80
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, _08198434 @ =FUN_08198d0c
	b _0819847E
	.align 2, 0
_08198430: .4byte 0x00000117
_08198434: .4byte FUN_08198d0c
_08198438: .4byte FUN_08199064
_0819843C: .4byte FUN_08199094
_08198440: .4byte FUN_081994e8
_08198444: .4byte FUN_08199568
_08198448: .4byte FUN_081996f0
_0819844C:
	cmp r0, #3
	bne _08198468
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x14
	str r0, [r1]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, _08198464 @ =FUN_0819926c
	b _0819847E
	.align 2, 0
_08198464: .4byte FUN_0819926c
_08198468:
	cmp r0, #4
	bne _08198480
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0x64
	str r0, [r1]
	movs r0, #0xba
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _0819849C @ =FUN_08199824
_0819847E:
	str r0, [r1]
_08198480:
	ldrh r1, [r6, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081984A0
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r0, [r0]
	movs r2, #0x89
	lsls r2, r2, #1
	adds r1, r5, r2
	b _08198512
	.align 2, 0
_0819849C: .4byte FUN_08199824
_081984A0:
	mov r4, sp
	adds r3, r7, #0
	adds r3, #0xc
	adds r2, r6, #0
	adds r2, #0xc
	ldrh r0, [r6, #0xc]
	ldrh r1, [r7, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _081984FC
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081984FC
	ldr r2, _081984F0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081984F4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081984F8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0x89
	lsls r2, r2, #1
	adds r1, r5, r2
	b _08198512
	.align 2, 0
_081984F0: .4byte 0x030046B8
_081984F4: .4byte 0x000003FF
_081984F8: .4byte 0x0203B400
_081984FC:
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	movs r3, #0x89
	lsls r3, r3, #1
	adds r1, r5, r3
_08198512:
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0xa2
	movs r0, #1
	strh r0, [r1]
	subs r1, #0x50
	strh r0, [r1]
	ldrh r0, [r6, #0x22]
	adds r1, #0x18
	strh r0, [r1]
	ldr r2, _08198560 @ =gSineTable
	movs r0, #0x89
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	adds r1, r5, #0
	adds r1, #0xf8
	strh r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	adds r1, #4
	strh r0, [r1]
	movs r0, #0xb8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0819857C
	.align 2, 0
_08198560: .4byte gSineTable
_08198564:
	ldrh r0, [r7, #0x3e]
	cmp r0, #0
	beq _08198574
_0819856A:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0819857C
_08198574:
	movs r0, #0xc8
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0819857C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
