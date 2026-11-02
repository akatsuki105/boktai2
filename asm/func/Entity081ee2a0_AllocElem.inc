	push {r4, r5, lr}
	movs r2, #0
	ldr r1, _081EDD44 @ =0x0000069C
	adds r3, r0, r1
	movs r5, #1
	movs r1, #0x4f
	adds r1, r1, r0
	mov ip, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081EDD34:
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081EDD48
	movs r0, #1
	b _081EDD4A
	.align 2, 0
_081EDD44: .4byte 0x0000069C
_081EDD48:
	movs r0, #0
_081EDD4A:
	cmp r0, #0
	bne _081EDD60
	adds r1, r5, #0
	lsls r1, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	mov r0, ip
	strb r2, [r0]
	adds r0, r4, #0
	b _081EDD6E
_081EDD60:
	movs r1, #0x40
	add ip, r1
	adds r4, #0x40
	adds r2, #1
	cmp r2, #0x19
	ble _081EDD34
	movs r0, #0
_081EDD6E:
	pop {r4, r5}
	pop {r1}
	bx r1
