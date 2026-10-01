	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _0809DF88 @ =0x03000140
	ldr r5, [r0]
	cmp r5, #0
	bne _0809DF90
	b _0809DFE4
	.align 2, 0
_0809DF88: .4byte 0x03000140
_0809DF8C:
	movs r0, #1
	b _0809DFE6
_0809DF90:
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r4, r0
	bge _0809DFE4
	adds r7, r0, #0
_0809DF9E:
	movs r0, #0xa8
	muls r0, r4, r0
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809DFDE
	movs r0, #0
	ldrsh r3, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	cmp r3, r0
	blt _0809DFDE
	movs r0, #4
	ldrsh r2, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xce
	ldrh r0, [r0]
	cmp r2, r0
	blt _0809DFDE
	adds r0, r1, #0
	adds r0, #0xd0
	ldrh r0, [r0]
	cmp r3, r0
	bgt _0809DFDE
	adds r0, r1, #0
	adds r0, #0xd2
	ldrh r0, [r0]
	cmp r2, r0
	ble _0809DF8C
_0809DFDE:
	adds r4, #1
	cmp r4, r7
	blt _0809DF9E
_0809DFE4:
	movs r0, #0
_0809DFE6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
