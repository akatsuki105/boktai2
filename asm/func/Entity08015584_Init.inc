	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	ldr r0, _0801551C @ =0x03000060
	mov r1, sl
	str r1, [r0]
	movs r0, #0
	str r0, [sp, #4]
	ldr r4, _08015520 @ =0x085AA914
	mov r7, sl
	adds r7, #0x18
_080154C6:
	ldrh r1, [r4]
	ldr r0, _08015524 @ =0x0000922E
	bl GetFile
	stm r7!, {r0}
	adds r4, #2
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #4]
	cmp r1, #1
	ble _080154C6
	ldr r0, _08015528 @ =0xFFFF0000
	movs r5, #0
	ands r6, r0
	movs r0, #0
	str r0, [sp, #4]
	mov sb, r0
	mov r1, sl
	adds r1, #0x8c
	str r1, [sp, #8]
	movs r0, #0x60
	add r0, sl
	mov r8, r0
	mov r7, sl
	adds r7, #0x44
	mov r4, sl
	adds r4, #0x24
_080154FC:
	mov r1, sb
	strb r1, [r4]
	mov r0, sb
	strh r0, [r4, #4]
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	strh r0, [r4, #0x14]
	adds r0, r7, #0
	ldr r1, _0801552C @ =0x00004384
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08015530
	movs r0, #1
	rsbs r0, r0, #0
	b _08015574
	.align 2, 0
_0801551C: .4byte 0x03000060
_08015520: .4byte 0x085AA914
_08015524: .4byte 0x0000922E
_08015528: .4byte 0xFFFF0000
_0801552C: .4byte 0x00004384
_08015530:
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0822a4b0
	mov r0, sl
	ldr r1, [r0, #0x18]
	mov r0, sb
	str r0, [sp]
	ldr r0, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	movs r0, #2
	mov r1, r8
	strb r0, [r1, #7]
	str r5, [r4, #0x58]
	str r6, [r4, #0x5c]
	ldr r0, [sp, #8]
	adds r0, #0x78
	str r0, [sp, #8]
	movs r1, #0x78
	add r8, r1
	adds r7, #0x78
	adds r4, #0x78
	ldr r0, [sp, #4]
	adds r0, #1
	str r0, [sp, #4]
	cmp r0, #0x1f
	ble _080154FC
	movs r0, #0
	mov r1, sl
	str r0, [r1, #0x20]
_08015574:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
