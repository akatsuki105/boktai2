	push {lr}
	adds r2, r0, #0
	cmp r1, #1
	beq _081B8686
	cmp r1, #1
	bgt _081B8676
	cmp r1, #0
	beq _081B8680
	b _081B86AC
_081B8676:
	cmp r1, #2
	beq _081B868C
	cmp r1, #3
	beq _081B86A0
	b _081B86AC
_081B8680:
	ldrh r0, [r2]
	adds r0, #0xff
	b _081B8690
_081B8686:
	ldrh r0, [r2, #4]
	adds r0, #0xff
	b _081B86A4
_081B868C:
	ldrh r0, [r2]
	subs r0, #0xff
_081B8690:
	ldr r1, _081B869C @ =0xFFFFFF00
	ands r0, r1
	adds r0, #0x80
	strh r0, [r2]
	b _081B86AC
	.align 2, 0
_081B869C: .4byte 0xFFFFFF00
_081B86A0:
	ldrh r0, [r2, #4]
	subs r0, #0xff
_081B86A4:
	ldr r1, _081B86B0 @ =0xFFFFFF00
	ands r0, r1
	adds r0, #0x80
	strh r0, [r2, #4]
_081B86AC:
	pop {r0}
	bx r0
	.align 2, 0
_081B86B0: .4byte 0xFFFFFF00
