	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _081967D0 @ =0x00000CCA
	adds r1, r4, r0
	movs r2, #0x89
	lsls r2, r2, #3
	adds r6, r4, r2
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	ble _0819675C
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081967D4 @ =0x00000169
	bl PlaySound_082406e0
_0819675C:
	movs r5, #0
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r5, r0
	bge _0819681E
	ldr r0, _081967D8 @ =0x00000AE6
	adds r2, r4, r0
	movs r7, #0
	ldr r1, _081967DC @ =0x0000044C
	adds r1, r1, r4
	mov sl, r1
	adds r3, r6, #0
	ldr r0, _081967E0 @ =0x00000C48
	adds r6, r4, r0
	ldr r1, _081967E4 @ =0x00000449
	adds r1, r1, r4
	mov ip, r1
	movs r0, #0x85
	lsls r0, r0, #3
	adds r0, r0, r4
	mov r8, r0
	ldr r1, _081967E8 @ =0x0000042C
	adds r1, r1, r4
	mov sb, r1
	adds r4, #0x60
	str r4, [sp]
_08196790:
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	mov r4, ip
	ldrb r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r1
	bne _08196814
	strb r1, [r2]
	mov r0, sl
	strh r7, [r0]
	strb r7, [r3]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	mov r3, sb
	movs r4, #0
	ldrsh r0, [r3, r4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _081967EC @ =0x000F423F
	cmp r1, r0
	bgt _081967F4
	ldr r3, _081967F0 @ =FUN_08196830
	str r3, [r6]
	b _0819681E
	.align 2, 0
_081967D0: .4byte 0x00000CCA
_081967D4: .4byte 0x00000169
_081967D8: .4byte 0x00000AE6
_081967DC: .4byte 0x0000044C
_081967E0: .4byte 0x00000C48
_081967E4: .4byte 0x00000449
_081967E8: .4byte 0x0000042C
_081967EC: .4byte 0x000F423F
_081967F0: .4byte FUN_08196830
_081967F4:
	ldr r3, _08196810 @ =FUN_08196978
	movs r4, #1
	ldr r1, [sp]
	adds r2, r1, #0
	adds r2, #0x84
_081967FE:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _081967FE
	str r3, [r6]
	b _0819681E
	.align 2, 0
_08196810: .4byte FUN_08196978
_08196814:
	adds r5, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r5, r0
	blt _08196790
_0819681E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
