	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	bl VM_ParseStringRef
	adds r1, r0, #0
	adds r4, r1, r4
	adds r0, r4, #0
	bl Textbox_LookupString
	adds r1, r0, #0
	cmp r1, #0
	beq _08048ADC
	b _08048AC0
_08048AB8:
	ldrb r0, [r1]
	strb r0, [r5]
	adds r1, #1
	adds r5, #1
_08048AC0:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08048AB8
	adds r0, r6, #0
	bl VM_ParseStringRef
	adds r1, r0, #0
	ldr r0, [sp, #0x10]
	adds r0, r1, r0
	bl Textbox_LookupString
	adds r1, r0, #0
	cmp r1, #0
	bne _08048AEC
_08048ADC:
	strb r1, [r5]
	movs r0, #1
	rsbs r0, r0, #0
	b _08048AF6
_08048AE4:
	ldrb r0, [r1]
	strb r0, [r5]
	adds r1, #1
	adds r5, #1
_08048AEC:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08048AE4
	strb r0, [r5]
	movs r0, #0
_08048AF6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
