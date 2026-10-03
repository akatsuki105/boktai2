	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl FUN_0809890c
	cmp r0, #0
	bne _0809898C
	movs r4, #7
	ldr r0, _080989C0 @ =0x0000F002
	adds r5, r0, #0
_0809896E:
	movs r0, #0
	movs r1, #0x12
	adds r2, r4, #0
	bl FUN_0808a420
	adds r2, r4, #1
	movs r1, #0xa
_0809897C:
	strh r5, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0809897C
	adds r4, r2, #0
	cmp r4, #0xa
	ble _0809896E
_0809898C:
	adds r0, r6, #0
	bl FUN_08098934
	cmp r0, #0
	bne _080989BA
	movs r4, #0xb
	ldr r0, _080989C0 @ =0x0000F002
	adds r5, r0, #0
_0809899C:
	movs r0, #0
	movs r1, #0x12
	adds r2, r4, #0
	bl FUN_0808a420
	adds r2, r4, #1
	movs r1, #0xa
_080989AA:
	strh r5, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _080989AA
	adds r4, r2, #0
	cmp r4, #0xe
	ble _0809899C
_080989BA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080989C0: .4byte 0x0000F002
