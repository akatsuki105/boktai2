	push {lr}
	adds r2, r0, #0
	mov ip, r1
	adds r1, #0x36
	ldrb r0, [r1]
	cmp r0, #0
	beq _081EDD88
	subs r0, #1
	strb r0, [r1]
	b _081EDDAC
_081EDD88:
	movs r0, #3
	strb r0, [r1]
	mov r3, ip
	adds r3, #0x37
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #1
	ands r0, r1
	strb r0, [r3]
	ldr r1, [r2, #0x18]
	mov r0, ip
	adds r0, #0x3c
	ldrb r2, [r0]
	ldrb r0, [r3]
	adds r2, r2, r0
	mov r0, ip
	bl Particle_SetPose
_081EDDAC:
	pop {r0}
	bx r0
