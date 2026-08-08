	push {r4, r5, r6, lr}
	sub sp, #0x10
	mov ip, r0
	adds r5, r1, #0
	mov r2, ip
	adds r2, #0x90
	movs r0, #0
	ldrsh r4, [r2, r0]
	ldrh r0, [r2]
	adds r0, r0, r5
	strh r0, [r2]
	mov r1, ip
	adds r1, #0x92
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r1]
	movs r6, #0
	ldrsh r1, [r1, r6]
	cmp r0, r1
	ble _0821D8B6
	strh r3, [r2]
_0821D8B6:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r4, r0
	beq _0821D8F0
	ldr r3, _0821D8F8 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0821D8FC @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	mov r3, ip
	adds r3, #0x50
	movs r0, #0xae
	lsls r0, r0, #1
	add r0, ip
	add r6, sp, #8
	str r6, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0805fe7c
_0821D8F0:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0821D8F8: .4byte 0xFFFF0000
_0821D8FC: .4byte 0x0000FFFF
