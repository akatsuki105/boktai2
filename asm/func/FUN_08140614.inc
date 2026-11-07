	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r4, _0814062C @ =0x00000664
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r0, #0
	blt _08140630
	asrs r0, r0, #7
	b _08140636
	.align 2, 0
_0814062C: .4byte 0x00000664
_08140630:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_08140636:
	cmp r0, #0
	bge _0814063C
	rsbs r0, r0, #0
_0814063C:
	adds r2, r0, #0
	cmp r2, #7
	ble _08140644
	movs r2, #7
_08140644:
	movs r1, #8
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r0, r3, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08140658
	movs r0, #1
	b _0814065A
_08140658:
	movs r0, #0
_0814065A:
	cmp r0, #0
	bne _0814066C
	ldr r0, _08140668 @ =0x085AD7E4
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	b _08140676
	.align 2, 0
_08140668: .4byte 0x085AD7E4
_0814066C:
	ldr r0, _0814067C @ =0x085AD7E4
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #6
_08140676:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0814067C: .4byte 0x085AD7E4
