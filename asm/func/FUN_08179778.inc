	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r6, #0
	movs r1, #1
	mov ip, r1
	movs r1, #0x80
	mov r8, r1
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r3, r0, r1
	adds r1, #0xfd
	adds r4, r0, r1
	movs r7, #0x92
	lsls r7, r7, #1
	movs r5, #7
_081797A0:
	ldrb r0, [r4]
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	beq _081797AE
	movs r0, #1
	b _081797B0
_081797AE:
	movs r0, #0
_081797B0:
	cmp r0, #0
	bne _081797DC
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081797C6
	subs r0, #1
	strh r0, [r1]
	b _081797DC
_081797C6:
	cmp r6, #1
	bgt _081797DC
	movs r0, #3
	strh r0, [r1]
	adds r2, r3, #0
	adds r2, #0xfd
	ldrb r1, [r2]
	mov r0, r8
	orrs r0, r1
	strb r0, [r2]
	adds r6, #1
_081797DC:
	adds r3, r3, r7
	adds r4, r4, r7
	subs r5, #1
	cmp r5, #0
	bge _081797A0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
