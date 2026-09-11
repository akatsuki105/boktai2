	push {r4, r5, r6, lr}
	ldr r0, _080B392C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080B39B0
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080B3930
	bl Script_GetValue
	adds r4, r0, #0
	cmp r4, #0xa
	ble _080B3932
	movs r4, #0xa
	b _080B3936
	.align 2, 0
_080B392C: .4byte 0x030047A4
_080B3930:
	movs r4, #0
_080B3932:
	cmp r4, #0
	ble _080B39B0
_080B3936:
	ldr r2, _080B3958 @ =0x030046A0
	ldr r5, [r2]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r5, r1
	movs r6, #0
	ldrsh r3, [r0, r6]
	subs r1, r3, #1
	ldr r0, _080B395C @ =0x0000270D
	cmp r1, r0
	bhi _080B398C
	movs r1, #0
	cmp r1, r4
	bge _080B3982
	ldr r6, _080B3960 @ =0x0000023A
	adds r0, r5, r6
	b _080B3970
	.align 2, 0
_080B3958: .4byte 0x030046A0
_080B395C: .4byte 0x0000270D
_080B3960: .4byte 0x0000023A
_080B3964:
	adds r1, #1
	cmp r1, r4
	bge _080B3982
	ldr r0, [r2]
	ldr r6, _080B39B8 @ =0x0000023A
	adds r0, r0, r6
_080B3970:
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	asrs r0, r0, #6
	adds r3, r0, #1
	ldr r0, _080B39BC @ =0x0000270E
	cmp r3, r0
	ble _080B3964
	ldr r3, _080B39C0 @ =0x0000270F
_080B3982:
	ldr r0, [r2]
	movs r6, #0x91
	lsls r6, r6, #4
	adds r0, r0, r6
	strh r3, [r0]
_080B398C:
	bl GetSecond
	adds r1, r0, #0
	ldr r4, _080B39C4 @ =0x030046A0
	ldr r0, [r4]
	movs r2, #0xad
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	eors r0, r1
	movs r1, #0xd
	bl Mod
	ldr r1, [r4]
	ldr r5, _080B39B8 @ =0x0000023A
	adds r1, r1, r5
	adds r0, #0x41
	strh r0, [r1]
_080B39B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B39B8: .4byte 0x0000023A
_080B39BC: .4byte 0x0000270E
_080B39C0: .4byte 0x0000270F
_080B39C4: .4byte 0x030046A0
