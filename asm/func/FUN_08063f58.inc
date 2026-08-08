	push {lr}
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08063F6A
	movs r0, #0
	b _08063F6C
_08063F6A:
	movs r0, #0xa
_08063F6C:
	pop {r1}
	bx r1
