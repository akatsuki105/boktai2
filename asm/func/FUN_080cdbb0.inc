	ldr r1, [r0, #0x18]
	adds r1, #0x22
	ldr r3, _080CDBF4 @ =0x00000938
	adds r2, r0, r3
	strh r1, [r2]
	ldr r1, _080CDBF8 @ =0x0000093A
	adds r2, r0, r1
	ldr r1, _080CDBFC @ =0x00000121
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	movs r1, #0x20
	strh r1, [r2]
	ldr r1, _080CDC00 @ =0x0000093E
	adds r2, r0, r1
	ldr r1, _080CDC04 @ =0x00000123
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	adds r1, #1
	strh r1, [r2]
	ldr r1, _080CDC08 @ =0x00000942
	adds r2, r0, r1
	movs r1, #0x1f
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	movs r1, #0x21
	strh r1, [r2]
	ldr r1, _080CDC0C @ =0x00000946
	adds r0, r0, r1
	movs r1, #0x1e
	strh r1, [r0]
	bx lr
	.align 2, 0
_080CDBF4: .4byte 0x00000938
_080CDBF8: .4byte 0x0000093A
_080CDBFC: .4byte 0x00000121
_080CDC00: .4byte 0x0000093E
_080CDC04: .4byte 0x00000123
_080CDC08: .4byte 0x00000942
_080CDC0C: .4byte 0x00000946
