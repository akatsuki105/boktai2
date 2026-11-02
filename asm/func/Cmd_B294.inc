	push {r4, r5, lr}
	ldr r0, _0805552C @ =0x03000120
	ldr r2, [r0]
	cmp r2, #0
	beq _0805554C
	movs r3, #1
	str r3, [r2, #0x5c]
	adds r0, r2, #0
	adds r0, #0x46
	ldrh r4, [r0]
	cmp r4, #0
	bne _0805554C
	movs r0, #2
	str r0, [r2, #0x58]
	ldr r1, _08055530 @ =0x0300445C
	movs r0, #0x40
	str r0, [r1]
	ldr r1, _08055534 @ =0x03004464
	ldr r5, _08055538 @ =0x00001084
	adds r0, r5, #0
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0x31
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _0805553C @ =0x030046A0
	ldr r0, [r1]
	movs r5, #0xeb
	lsls r5, r5, #2
	adds r0, r0, r5
	strh r3, [r0]
	adds r0, r2, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	bne _08055544
	ldr r0, [r1]
	ldr r1, _08055540 @ =0x000003AE
	adds r0, r0, r1
	strh r3, [r0]
	b _0805554C
	.align 2, 0
_0805552C: .4byte 0x03000120
_08055530: .4byte 0x0300445C
_08055534: .4byte 0x03004464
_08055538: .4byte 0x00001084
_0805553C: .4byte 0x030046A0
_08055540: .4byte 0x000003AE
_08055544:
	ldr r0, [r1]
	ldr r5, _08055554 @ =0x000003AE
	adds r0, r0, r5
	strh r4, [r0]
_0805554C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08055554: .4byte 0x000003AE
