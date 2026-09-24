	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	mov sl, r1
	movs r7, #0
	movs r5, #0
	mov r0, sl
	lsls r0, r0, #2
	str r0, [sp, #8]
	ldr r1, [sp]
	ldr r2, _081DC984 @ =0x000006FC
	adds r0, r1, r2
	add r0, sl
	mov sb, r0
	mov r0, sl
	lsls r0, r0, #5
	mov r8, r0
_081DC8EA:
	ldr r4, _081DC988 @ =0x085AE248
	add r4, r8
	movs r6, #6
_081DC8F0:
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #3
	bl FUN_081dc8a0
	adds r3, r0, #0
	lsls r1, r7, #1
	mov r2, sb
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r0, _081DC98C @ =0x085AE208
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r7, #1
	adds r4, #4
	subs r6, #2
	cmp r6, #0
	bge _081DC8F0
	movs r0, #0x10
	add r8, r0
	adds r5, #1
	cmp r5, #1
	ble _081DC8EA
	movs r7, #0
	movs r5, #0
	ldr r0, [sp, #8]
	add r0, sl
	lsls r0, r0, #3
	str r0, [sp, #4]
	ldr r1, [sp]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r1, r2
	add r0, sl
	mov r8, r0
_081DC942:
	adds r0, r5, #1
	mov sb, r0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	ldr r1, [sp, #4]
	adds r0, r0, r1
	ldr r2, _081DC990 @ =0x085AE32C
	adds r4, r0, r2
	movs r6, #8
_081DC956:
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #3
	bl FUN_081dc8a0
	adds r3, r0, #0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _081DC998
	lsls r2, r7, #1
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r0, _081DC994 @ =0x085AE2C8
	adds r2, r2, r0
	ldrh r0, [r2]
	movs r2, #0xc0
	lsls r2, r2, #6
	b _081DC9B0
	.align 2, 0
_081DC984: .4byte 0x000006FC
_081DC988: .4byte 0x085AE248
_081DC98C: .4byte 0x085AE208
_081DC990: .4byte 0x085AE32C
_081DC994: .4byte 0x085AE2C8
_081DC998:
	lsls r2, r7, #1
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r1, _081DC9D8 @ =0x085AE2C8
	adds r2, r2, r1
	ldrh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #6
_081DC9B0:
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r7, #1
	adds r4, #4
	subs r6, #2
	cmp r6, #0
	bge _081DC956
	mov r5, sb
	cmp r5, #1
	ble _081DC942
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC9D8: .4byte 0x085AE2C8
