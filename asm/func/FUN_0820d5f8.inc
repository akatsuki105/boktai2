	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0820D628 @ =0x0000110E
	adds r4, r5, r0
	ldrh r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0820D630
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0820D67E
	bl FUN_08049e5c
	bl FUN_08049fa8
	ldrh r0, [r4]
	ldr r1, _0820D62C @ =0x0000FFFD
	ands r1, r0
	movs r0, #4
	orrs r1, r0
	strh r1, [r4]
	b _0820D67E
	.align 2, 0
_0820D628: .4byte 0x0000110E
_0820D62C: .4byte 0x0000FFFD
_0820D630:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0820D67E
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0820D650
	bl FUN_08049e5c
	bl FUN_08049f5c
	ldrh r1, [r4]
	ldr r0, _0820D684 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r4]
_0820D650:
	bl FUN_08049e5c
	ldr r1, _0820D688 @ =0x0000124C
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r1, r5, #0
	adds r1, #0x26
	ldrb r1, [r1]
	adds r0, r0, r1
	bl Textbox_LookupString
	bl FUN_08049e30
	ldrh r1, [r4]
	ldr r0, _0820D68C @ =0x0000FFF7
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, _0820D684 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r4]
_0820D67E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0820D684: .4byte 0x0000FFFB
_0820D688: .4byte 0x0000124C
_0820D68C: .4byte 0x0000FFF7
