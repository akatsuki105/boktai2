	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	mov sb, r1
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, #0x24
	ldrb r7, [r0]
	adds r0, r7, #0
	movs r1, #0x63
	mov r8, r1
	cmp r0, #0
	beq _080AC252
	movs r2, #0x6c
	mov r8, r2
	cmp r0, #1
	bne _080AC252
	movs r0, #0x62
	mov r8, r0
_080AC252:
	adds r6, r4, #0
	adds r6, #0x2c
	ldr r1, _080AC2D4 @ =0x00000BA8
	adds r0, r6, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	strh r7, [r4, #0x10]
	movs r0, #3
	strb r0, [r4, #7]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r5, #0x1c]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldrh r0, [r5, #0x1e]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	ldrh r0, [r5, #0x20]
	ldrh r1, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r4]
	ldr r0, _080AC2D8 @ =0x03003584
	mov r2, r8
	lsls r1, r2, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r4, #0x48]
	ldr r5, _080AC2DC @ =0x00003DEF
	adds r2, r4, #0
	adds r2, #0x4c
	adds r3, r4, #0
	adds r3, #0x6c
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x6a
_080AC2B6:
	strh r5, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080AC2B6
	mov r0, r8
	strh r0, [r6, #6]
	str r2, [r6, #0xc]
	movs r0, #1
	strb r0, [r3]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC2D4: .4byte 0x00000BA8
_080AC2D8: .4byte 0x03003584
_080AC2DC: .4byte 0x00003DEF
