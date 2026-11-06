	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6, #0x1d]
	cmp r0, #0
	beq _080517D2
	movs r1, #0
	strb r1, [r6, #0x1d]
	adds r0, r6, #0
	adds r0, #0x2c
	strb r1, [r0]
	movs r7, #0
	movs r0, #0x8c
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0x6c
	adds r1, r1, r6
	mov sl, r1
	adds r0, r6, #0
	adds r0, #0x2d
	str r0, [sp]
	movs r1, #3
	mov sb, r1
	movs r0, #0x28
	adds r0, r0, r6
	mov ip, r0
	adds r5, r6, #0
	adds r5, #0xec
_08051750:
	adds r4, r7, #0
	mov r1, sb
	ands r4, r1
	cmp r7, #3
	bgt _08051774
	mov r0, ip
	adds r3, r0, r4
	adds r0, r6, #0
	adds r0, #0x24
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r2, #0
	strb r1, [r3]
	strb r2, [r0]
	movs r0, #0
	strb r4, [r5, #2]
	strb r0, [r5, #3]
	b _080517A4
_08051774:
	mov r1, ip
	adds r0, r1, r4
	adds r1, r5, #0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r4, [r5, #2]
	cmp r0, #0xa
	ble _0805178A
	movs r0, #0xa
	b _08051790
_0805178A:
	cmp r0, #0
	bge _08051790
	movs r0, #0
_08051790:
	movs r2, #0
	strb r0, [r1, #3]
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _080517A4
	mov r0, sb
	strb r0, [r5]
	movs r0, #1
	strb r0, [r5, #1]
	str r2, [r5, #8]
_080517A4:
	adds r5, #0x7c
	adds r7, #1
	cmp r7, #7
	ble _08051750
	movs r4, #8
	mov r0, r8
	mov r1, sl
	movs r2, #0x31
	movs r3, #0
	bl MainSprite_SetPose
	mov r1, r8
	ldr r0, [r1, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r1, r8
	str r0, [r1, #8]
	ldr r0, [sp]
	strb r4, [r0]
	ldr r0, _0805182C @ =0x00000373
	bl PlaySound_082406e0
_080517D2:
	ldr r0, [r6, #0x18]
	cmp r0, #0x28
	bne _080517FC
	movs r1, #0
	movs r7, #0
	adds r2, r6, #0
	adds r2, #0x28
_080517E0:
	adds r0, r2, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r1, r0
	adds r7, #1
	cmp r7, #3
	ble _080517E0
	cmp r1, #0
	bne _080517FC
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080517FC:
	ldr r0, [r6, #0x18]
	cmp r0, #0x4f
	bls _08051816
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	adds r0, r6, #0
	movs r1, #0
	bl Entity08051b70_NextBlockStep
_08051816:
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805182C: .4byte 0x00000373
