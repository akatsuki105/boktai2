	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r4, r2, r0
	movs r5, #1
	mov ip, r3
_080DC060:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080DC070
	movs r0, #1
	b _080DC072
_080DC070:
	movs r0, #0
_080DC072:
	cmp r0, #0
	bne _080DC08C
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	adds r0, r2, r0
	strb r3, [r0, #0x17]
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _080DC098
_080DC08C:
	movs r0, #0x1c
	add ip, r0
	adds r3, #1
	cmp r3, #7
	ble _080DC060
	movs r0, #0
_080DC098:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
