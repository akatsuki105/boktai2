	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	adds r7, r1, #0
	ldr r1, [sp, #0x40]
	ldr r5, [sp, #0x44]
	mov r0, sp
	movs r4, #0
	strh r2, [r0]
	strh r3, [r0, #2]
	strh r1, [r0, #6]
	strh r4, [r0, #8]
	strh r4, [r0, #0xa]
	strh r5, [r0, #0xc]
	strh r4, [r0, #0xe]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, #0
	bl Div
	adds r6, r0, #0
	mov r0, sp
	strh r4, [r0, #0x12]
	strh r4, [r0, #0x10]
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x1a]
	add r2, sp, #0x4c
	ldrh r2, [r2]
	strh r2, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r0, #0x20]
	strh r4, [r0, #0x22]
	add r2, sp, #0x4c
	ldrh r2, [r2]
	strh r2, [r0, #0x24]
	strh r4, [r0, #0x26]
	mov r1, sp
	movs r0, #0xa
	strh r0, [r1, #0x16]
	mov r0, sp
	strh r4, [r0, #0x14]
	cmp r7, #0
	ble _08015B0C
	mov r5, sp
	adds r4, r7, #0
_08015AF6:
	movs r0, #1
	mov r1, r8
	mov r2, sp
	bl FUN_080155e4
	ldrh r0, [r5, #0x14]
	adds r0, r0, r6
	strh r0, [r5, #0x14]
	subs r4, #1
	cmp r4, #0
	bne _08015AF6
_08015B0C:
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
