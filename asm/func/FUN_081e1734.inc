	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #4
	mov ip, r0
	movs r6, #0
_081E173E:
	lsls r1, r6, #2
	adds r0, r7, #0
	adds r0, #0x5c
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081E17B2
	lsls r0, r6, #3
	adds r3, r0, r7
	adds r3, #0x3c
	adds r5, r1, #0
	adds r5, #0x2c
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E1772
	asrs r0, r0, #8
	b _081E1778
_081E1772:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E1778:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E178A
	asrs r0, r0, #8
	b _081E1790
_081E178A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E1790:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081E17A4
	asrs r1, r0, #8
	b _081E17AA
_081E17A4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_081E17AA:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_081E17B2:
	adds r6, #1
	cmp r6, ip
	blt _081E173E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
