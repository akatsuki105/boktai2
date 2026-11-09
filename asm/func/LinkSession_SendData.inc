	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x7e
	adds r0, r0, r4
	mov ip, r0
	ldrh r3, [r0]
	cmp r3, r2
	bge _081DDB54
	ldr r0, [r4, #0x48]
	cmp r0, #0
	blt _081DDB50
	adds r0, r1, r3
	ldrb r1, [r0]
	movs r0, #3
	ands r3, r0
	lsls r0, r3, #8
	orrs r1, r0
	movs r0, #0x80
	lsls r0, r0, #4
	orrs r1, r0
	adds r0, r4, #0
	adds r0, #0x42
	strh r1, [r0]
	mov r1, ip
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, r2
	bge _081DDB54
_081DDB50:
	movs r0, #0
	b _081DDB56
_081DDB54:
	movs r0, #1
_081DDB56:
	pop {r4}
	pop {r1}
	bx r1
