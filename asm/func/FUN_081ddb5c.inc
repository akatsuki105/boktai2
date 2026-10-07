	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	lsls r2, r5, #1
	adds r0, #0x80
	adds r0, r0, r2
	ldrh r1, [r0]
	cmp r1, r7
	bge _081DDBCE
	adds r4, r4, r1
	mov ip, r4
	cmp r5, #0
	bge _081DDB84
	ldr r0, _081DDB80 @ =0x0000FFFF
	b _081DDB8A
	.align 2, 0
_081DDB80: .4byte 0x0000FFFF
_081DDB84:
	ldr r0, [r6, #0x44]
	adds r0, r2, r0
	ldrh r0, [r0]
_081DDB8A:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0xf0
	lsls r0, r0, #6
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #4
	cmp r0, r1
	bne _081DDBA0
	movs r0, #1
	b _081DDBA2
_081DDBA0:
	movs r0, #0
_081DDBA2:
	cmp r0, #0
	beq _081DDBD2
	movs r1, #0xc0
	lsls r1, r1, #2
	ands r1, r4
	lsls r2, r5, #1
	adds r0, r6, #0
	adds r0, #0x80
	adds r2, r0, r2
	ldrh r3, [r2]
	movs r0, #3
	lsrs r1, r1, #8
	ands r0, r3
	cmp r1, r0
	bne _081DDBD2
	mov r0, ip
	strb r4, [r0]
	adds r0, r3, #1
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, r7
	blt _081DDBD2
_081DDBCE:
	movs r0, #1
	b _081DDBD4
_081DDBD2:
	movs r0, #0
_081DDBD4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
