	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r1, _080B1B14 @ =0x00000C0F
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B1B0A
	movs r2, #0x95
	lsls r2, r2, #2
	adds r4, r6, r2
	mov r8, r4
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r5, r6, r0
	ldr r1, _080B1B18 @ =0x0000C039
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #3
	strb r0, [r4, #7]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0822b234
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r7, r6, r1
	ldr r2, [r5, #0xc]
	adds r1, r7, #0
	movs r3, #0xf
_080B1AD2:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _080B1AD2
	str r7, [r5, #0xc]
	adds r0, r4, #0
	adds r0, #0x6a
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, r8
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #1
	strh r0, [r1]
_080B1B0A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1B14: .4byte 0x00000C0F
_080B1B18: .4byte 0x0000C039
