	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r6, #1
	rsbs r6, r6, #0
	ldr r0, _080A782C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A7834
	ldr r1, _080A7830 @ =0x00000343
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r6, #1
	cmp r0, #0
	beq _080A7824
	movs r6, #0
_080A7824:
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _080A7844
	.align 2, 0
_080A782C: .4byte 0x030044E0
_080A7830: .4byte 0x00000343
_080A7834:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080A7844
	movs r6, #0
	movs r0, #0xde
	bl PlaySound_082406e0
_080A7844:
	cmp r6, #0
	bne _080A789C
	movs r2, #0xb0
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	bl FUN_08047864
	movs r0, #7
	bl FUN_0809c08c
	ldr r0, _080A788C @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807adc0
	movs r0, #2
	bl sound_fadeout_08240440
	ldr r3, _080A7890 @ =0x00000346
	adds r0, r5, r3
	strh r6, [r0]
	ldr r1, _080A7894 @ =0x00000343
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _080A7898 @ =0x00000341
	adds r1, r5, r2
	movs r0, #6
	strb r0, [r1]
	subs r3, #6
	adds r1, r5, r3
	movs r0, #4
	strb r0, [r1]
	b _080A79A2
	.align 2, 0
_080A788C: .4byte 0x03002BE0
_080A7890: .4byte 0x00000346
_080A7894: .4byte 0x00000343
_080A7898: .4byte 0x00000341
_080A789C:
	cmp r6, #1
	bne _080A7918
	movs r0, #2
	bl sound_fadeout_08240440
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	movs r3, #1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #7
_080A78BA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x50
	subs r2, #1
	cmp r2, #0
	bge _080A78BA
	bl FUN_08047864
	movs r0, #7
	bl FUN_0809c08c
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A790A
	ldr r1, _080A7914 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r1, [r0]
	lsls r1, r1, #1
	subs r3, #4
	adds r0, r5, r3
	adds r0, r0, r1
	ldrh r0, [r0]
	str r0, [sp]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080A790A:
	adds r0, r5, #0
	bl KillEntity
	b _080A79A2
	.align 2, 0
_080A7914: .4byte 0xFFFF0000
_080A7918:
	movs r2, #0
	ldr r0, _080A7934 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080A793C
	ldr r1, _080A7938 @ =0x00000343
	adds r0, r5, r1
	ldrb r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r2, r0, #0x1f
	b _080A7950
	.align 2, 0
_080A7934: .4byte 0x030044E0
_080A7938: .4byte 0x00000343
_080A793C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A7950
	ldr r3, _080A7984 @ =0x00000343
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A7950
	movs r2, #1
_080A7950:
	cmp r2, #0
	beq _080A799C
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080A7984 @ =0x00000343
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A7988
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xa6
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0x88
	movs r3, #1
	bl Sprite_SetSprite
	b _080A799C
	.align 2, 0
_080A7984: .4byte 0x00000343
_080A7988:
	movs r3, #0xae
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r2, #0xa6
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0x87
	movs r3, #1
	bl Sprite_SetSprite
_080A799C:
	adds r0, r5, #0
	bl FUN_080a74fc
_080A79A2:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
