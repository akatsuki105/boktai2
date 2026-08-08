	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	mov r8, r1
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08032EB6
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032E5C
	ldr r1, _08032E58 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x49
	subs r1, #4
	adds r6, r4, r1
	cmp r0, #0
	bne _08032E6E
	movs r3, #0x48
	b _08032E6E
	.align 2, 0
_08032E58: .4byte 0x00000824
_08032E5C:
	movs r3, #0x82
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r1, [r0]
	movs r3, #0x48
	adds r6, r0, #0
	cmp r1, #0
	beq _08032E6E
	movs r3, #0x49
_08032E6E:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r7, #0
	str r7, [sp, #4]
	adds r0, r4, #0
	bl FUN_08022da8
	ldr r0, [r6]
	cmp r0, #0
	bne _08032E92
	adds r0, r5, #0
	bl FUN_0802a538
_08032E92:
	movs r1, #0x8e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_08023090
	movs r3, #0xc5
	lsls r3, r3, #2
	adds r1, r5, r3
	adds r0, r4, #0
	bl FUN_08022fb8
	bl FUN_080846f8
	ldr r1, _08032ECC @ =0x00001044
	adds r0, r5, r1
	str r7, [r0]
_08032EB6:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08032ED0
	subs r0, r2, #4
	b _08032ED2
	.align 2, 0
_08032ECC: .4byte 0x00001044
_08032ED0:
	movs r0, #0
_08032ED2:
	strh r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	ble _08032EE8
	subs r0, r2, #4
	b _08032EEA
_08032EE8:
	movs r0, #0
_08032EEA:
	strh r0, [r1]
	movs r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r8, r0
	bne _08032F0C
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_08023024
_08032F0C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
