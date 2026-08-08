	push {r4, r5, lr}
	mov ip, r0
	lsls r1, r1, #2
	lsls r2, r2, #2
	ldr r4, _080E5100 @ =0x085B0A08
	ldr r5, _080E5104 @ =0x000001DD
	add r5, ip
	ldrb r0, [r5]
	adds r0, #0x40
	movs r3, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	mov r1, ip
	ldrh r1, [r1, #8]
	adds r0, r0, r1
	movs r1, #0x83
	lsls r1, r1, #2
	add r1, ip
	strh r0, [r1]
	mov r3, ip
	ldrh r1, [r3, #0xa]
	ldr r0, _080E5108 @ =0x0000020E
	add r0, ip
	strh r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	asrs r0, r0, #0xc
	ldrh r2, [r3, #0xc]
	adds r0, r0, r2
	movs r1, #0x84
	lsls r1, r1, #2
	add r1, ip
	strh r0, [r1]
	movs r2, #0x85
	lsls r2, r2, #2
	add r2, ip
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080E5100: .4byte 0x085B0A08
_080E5104: .4byte 0x000001DD
_080E5108: .4byte 0x0000020E
