	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #8]
	adds r5, r1, #0
	str r2, [sp, #0xc]
	adds r7, r3, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E805C
	adds r0, #4
	b _080E8068
_080E805C:
	ldr r0, _080E8080 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E8068:
	ldrb r0, [r0]
	lsrs r6, r0, #4
	mov r4, sp
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E8084
	adds r0, #4
	b _080E8090
	.align 2, 0
_080E8080: .4byte 0x030046A4
_080E8084:
	ldr r2, _080E80A4 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E8090:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E80A8
	cmp r2, #2
	beq _080E80AC
	b _080E80B0
	.align 2, 0
_080E80A4: .4byte 0x030046A4
_080E80A8:
	ldrb r0, [r4, #4]
	b _080E80AE
_080E80AC:
	ldrb r0, [r4]
_080E80AE:
	subs r1, r1, r0
_080E80B0:
	mov r8, r1
	mov sl, sp
	ldr r1, _080E80F0 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _080E80F0 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E80F4
	adds r0, #4
	b _080E8100
	.align 2, 0
_080E80F0: .4byte 0x030046A4
_080E80F4:
	ldr r1, _080E8138 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E8100:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r2, sl
	strh r1, [r2, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r2, #4]
	movs r4, #0
	cmp r6, #2
	bne _080E811E
	cmp r7, #0
	beq _080E8126
_080E811E:
	cmp r7, #2
	bne _080E813C
	cmp r6, #0
	bne _080E813C
_080E8126:
	ldr r2, [sp, #8]
	subs r0, r2, r5
	cmp r0, #0
	bge _080E8130
	rsbs r0, r0, #0
_080E8130:
	cmp r0, #1
	bne _080E817E
	b _080E817C
	.align 2, 0
_080E8138: .4byte 0x030046A4
_080E813C:
	cmp r6, #1
	bne _080E8144
	cmp r7, #0
	beq _080E814C
_080E8144:
	cmp r7, #1
	bne _080E816C
	cmp r6, #0
	bne _080E816C
_080E814C:
	ldr r0, [sp, #8]
	subs r1, r0, r5
	cmp r1, #0
	bge _080E8156
	rsbs r1, r1, #0
_080E8156:
	ldr r0, _080E8168 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _080E817E
	b _080E817C
	.align 2, 0
_080E8168: .4byte 0x030046A4
_080E816C:
	cmp r6, #1
	bne _080E8174
	cmp r7, #1
	beq _080E817C
_080E8174:
	cmp r6, #2
	bne _080E817E
	cmp r7, #2
	bne _080E817E
_080E817C:
	movs r4, #1
_080E817E:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E818E
	adds r0, #4
	b _080E819A
_080E818E:
	ldr r0, _080E81C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E819A:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _080E81BC
	cmp r4, #0
	beq _080E81C4
	mov r0, r8
	asrs r0, r0, #8
	ldr r1, [sp, #0xc]
	asrs r1, r1, #8
	subs r0, r0, r1
	cmp r0, #0
	bge _080E81B8
	rsbs r0, r0, #0
_080E81B8:
	cmp r0, #1
	ble _080E81CA
_080E81BC:
	movs r0, #0
	b _080E81CC
	.align 2, 0
_080E81C0: .4byte 0x030046A4
_080E81C4:
	ldr r2, [sp, #0xc]
	cmp r8, r2
	bne _080E81BC
_080E81CA:
	movs r0, #1
_080E81CC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
