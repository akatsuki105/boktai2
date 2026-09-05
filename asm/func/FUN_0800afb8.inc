	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0800B05C @ =0x03000044
	ldr r7, [r0]
	cmp r7, #0
	beq _0800B04A
	movs r1, #0
_0800AFCE:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x28
	adds r5, r7, r0
	ldrb r0, [r5]
	adds r1, #1
	mov sb, r1
	cmp r0, #0
	beq _0800B044
	ldrb r0, [r5, #2]
	cmp r0, #2
	bne _0800B044
	movs r0, #0
	strb r0, [r5, #2]
	ldr r0, _0800B060 @ =0x085AA6D0
	mov sl, r0
	adds r4, r5, #0
	adds r4, #8
	adds r6, r5, #0
	adds r6, #0x20
	movs r2, #3
	mov r8, r2
_0800B000:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800B034
	ldr r1, [r7, #0x24]
	ldr r2, [r7, #0x18]
	lsls r0, r2, #1
	adds r0, r0, r2
	ldrb r2, [r5, #2]
	adds r0, r0, r2
	lsls r0, r0, #2
	add r0, sl
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_08236fac
	ldrb r0, [r4]
	cmp r0, #2
	bhi _0800B034
	ldrh r0, [r4, #4]
	cmp r0, #0xb3
	bhi _0800B034
	movs r0, #0xb4
	strh r0, [r4, #4]
_0800B034:
	adds r4, #0x50
	adds r6, #0x50
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r2, r8
	cmp r2, #0
	bge _0800B000
_0800B044:
	mov r1, sb
	cmp r1, #5
	ble _0800AFCE
_0800B04A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800B05C: .4byte 0x03000044
_0800B060: .4byte 0x085AA6D0
