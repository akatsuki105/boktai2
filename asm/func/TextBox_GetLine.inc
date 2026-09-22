	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	pop {r4}
	pop {r1}
	bx r1
