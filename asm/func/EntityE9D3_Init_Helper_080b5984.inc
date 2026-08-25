	push {lr}
	ldr r0, _080B599C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080B59A0 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #1
	bgt _080B59A4
	movs r0, #9
	b _080B59B0
	.align 2, 0
_080B599C: .4byte 0x030046A0
_080B59A0: .4byte 0x00000942
_080B59A4:
	cmp r1, #9
	bgt _080B59AE
	movs r0, #0xb
	subs r0, r0, r1
	b _080B59B0
_080B59AE:
	movs r0, #2
_080B59B0:
	pop {r1}
	bx r1
