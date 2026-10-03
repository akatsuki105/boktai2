	push {r4, lr}
	ldr r0, _0809C62C @ =0x0300013C
	ldr r3, [r0]
	cmp r3, #0
	beq _0809C624
	movs r1, #0xa1
	lsls r1, r1, #4
	adds r0, r3, r1
	movs r2, #0
	movs r1, #0xa
	strh r1, [r0]
	ldr r4, _0809C630 @ =0x00000A0E
	adds r0, r3, r4
	strh r1, [r0]
	ldr r0, _0809C634 @ =0x00000A12
	adds r1, r3, r0
	movs r0, #0xb4
	strh r0, [r1]
	ldr r1, _0809C638 @ =0x00000A14
	adds r0, r3, r1
	strb r2, [r0]
	adds r0, r3, #0
	bl FUN_0808ad5c
_0809C624:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C62C: .4byte 0x0300013C
_0809C630: .4byte 0x00000A0E
_0809C634: .4byte 0x00000A12
_0809C638: .4byte 0x00000A14
