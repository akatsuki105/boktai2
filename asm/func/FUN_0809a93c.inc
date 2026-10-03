	push {r4, r5, lr}
	adds r4, r1, #0
	adds r2, r4, #1
	cmp r2, #9
	ble _0809A948
	movs r2, #0
_0809A948:
	movs r3, #0
	ldr r5, _0809A95C @ =0x00000F58
	adds r1, r0, r5
_0809A94E:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A960
	adds r0, r2, #0
	b _0809A970
	.align 2, 0
_0809A95C: .4byte 0x00000F58
_0809A960:
	adds r2, #1
	cmp r2, #9
	ble _0809A968
	movs r2, #0
_0809A968:
	adds r3, #1
	cmp r3, #9
	ble _0809A94E
	adds r0, r4, #0
_0809A970:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
