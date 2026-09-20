	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #1
	strh r1, [r0]
	ldr r2, _080A74F0 @ =0x0000033E
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0
	movs r0, #0
	mov sl, r0
	adds r4, r7, #0
	adds r4, #0x28
	adds r5, r7, #0
	adds r5, #0x18
	adds r6, r7, #0
	adds r6, #0x44
	mov r8, r5
	movs r1, #0x38
	mov sb, r1
_080A747E:
	mov r2, sb
	strh r2, [r4, #0x38]
	movs r0, #0x48
	strh r0, [r4, #0x3a]
	cmp r3, #3
	ble _080A7490
	mov r0, sb
	adds r0, #0x10
	strh r0, [r4, #0x38]
_080A7490:
	adds r0, r6, #0
	ldr r1, _080A74F4 @ =0x0000654B
	str r3, [sp]
	bl Video_GetAuxSprite
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Setup
	mov r0, sl
	strb r0, [r5, #7]
	ldr r0, _080A74F8 @ =0x00001033
	str r0, [r5]
	ldrh r0, [r4, #0x38]
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0x3a]
	strh r0, [r4, #0xe]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	strb r0, [r5, #8]
	ldr r2, _080A74F0 @ =0x0000033E
	adds r0, r7, r2
	ldrh r0, [r0]
	strb r0, [r5, #9]
	ldr r3, [sp]
	strh r3, [r4]
	adds r4, #0x50
	adds r5, #0x50
	adds r6, #0x50
	movs r0, #0x50
	add r8, r0
	movs r1, #0x10
	add sb, r1
	adds r3, #1
	cmp r3, #7
	ble _080A747E
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A74F0: .4byte 0x0000033E
_080A74F4: .4byte 0x0000654B
_080A74F8: .4byte 0x00001033
