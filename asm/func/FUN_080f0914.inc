	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F099E
	movs r5, #1
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, [r2]
	ands r5, r1
	cmp r5, #0
	bne _080F099E
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080F099E
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	ldr r1, _080F0984 @ =0x0000044C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F0956
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013698
_080F0956:
	adds r2, r4, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _080F0988 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
	ldr r1, _080F098C @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F0990
	ldr r2, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F099E
	.align 2, 0
_080F0984: .4byte 0x0000044C
_080F0988: .4byte 0x0000FFFB
_080F098C: .4byte 0x0000025D
_080F0990:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_080F099E:
	pop {r4, r5}
	pop {r0}
	bx r0
