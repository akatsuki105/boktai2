	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r0, _080D06F4 @ =0x00000292
	add r0, ip
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r2, r1
	beq _080D0728
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080D06F8
_080D06F0:
	adds r0, r2, #0
	b _080D0730
	.align 2, 0
_080D06F4: .4byte 0x00000292
_080D06F8:
	adds r4, r2, #1
	movs r0, #7
	ands r4, r0
	adds r3, r2, #7
	ands r3, r0
	movs r5, #2
	adds r6, r1, #0
	movs r1, #0xa5
	lsls r1, r1, #2
	add r1, ip
_080D070C:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r6
	beq _080D0720
	cmp r0, r4
	beq _080D0730
	cmp r0, r3
	beq _080D0730
	cmp r0, r2
	bne _080D06F0
_080D0720:
	adds r1, #2
	adds r5, #1
	cmp r5, #9
	ble _080D070C
_080D0728:
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
_080D0730:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
