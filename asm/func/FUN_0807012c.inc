	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	mov r6, sp
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080700a4
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08070168
	cmp r1, #0
	blt _08070168
	ldr r0, _08070170 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08070168
	ldr r0, _08070174 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0807017C
_08070168:
	movs r4, #0
	ldr r2, _08070178 @ =0x030046A4
	b _0807018A
	.align 2, 0
_08070170: .4byte 0x030046A8
_08070174: .4byte 0x030046AC
_08070178: .4byte 0x030046A4
_0807017C:
	ldr r2, _08070198 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0807018A:
	ldr r0, [r2]
	ldr r2, [r0, #4]
	cmp r2, #0
	bne _0807019C
	movs r0, #0
	b _080701A2
	.align 2, 0
_08070198: .4byte 0x030046A4
_0807019C:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r0, r2, r0
_080701A2:
	mov r5, sp
	mov r1, sp
	bl FUN_08070104
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	ble _080701B6
	movs r0, #1
	b _080701D8
_080701B6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080701D6
	adds r0, #4
	mov r1, sp
	bl FUN_08070104
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	ble _080701D6
	movs r0, #2
	b _080701D8
_080701D6:
	movs r0, #0
_080701D8:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
