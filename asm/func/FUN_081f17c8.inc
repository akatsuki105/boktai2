	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0x1c
	adds r0, r0, r6
	mov sb, r0
	movs r7, #0
	mov r8, r7
	movs r5, #0
	adds r3, r6, #0
	adds r3, #0x93
	adds r4, r6, #0
	adds r4, #0x93
	mov ip, sb
_081F17E8:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _081F17F8
	movs r0, #1
	b _081F17FA
_081F17F8:
	movs r0, #0
_081F17FA:
	cmp r0, #0
	beq _081F1836
	mov r0, sb
	adds r0, #0x6c
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081F1836
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F1818
	subs r0, #1
	strb r0, [r3]
	b _081F1836
_081F1818:
	mov r0, r8
	cmp r0, #5
	bgt _081F1836
	movs r0, #3
	strb r0, [r4]
	mov r2, ip
	adds r2, #0x6c
	ldrh r1, [r2]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r7, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	add r8, r0
_081F1836:
	adds r3, #0x78
	adds r4, #0x78
	movs r7, #0x78
	add ip, r7
	adds r5, #1
	cmp r5, #0x17
	ble _081F17E8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
