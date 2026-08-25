	push {lr}
	mov ip, r0
	ldr r0, _080AAD74 @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _080AAD70
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	mov r1, ip
	adds r1, #0x7c
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r3, r0, r1
	cmp r3, #0
	bge _080AAD50
	rsbs r3, r3, #0
_080AAD50:
	movs r1, #0x30
	ldrsh r0, [r2, r1]
	mov r1, ip
	adds r1, #0x80
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _080AAD64
	rsbs r0, r0, #0
_080AAD64:
	mov r2, ip
	ldrh r1, [r2, #0x1a]
	cmp r3, r1
	bgt _080AAD70
	cmp r0, r1
	ble _080AAD78
_080AAD70:
	movs r0, #0
	b _080AAD7A
	.align 2, 0
_080AAD74: .4byte 0x03002BE0
_080AAD78:
	movs r0, #1
_080AAD7A:
	pop {r1}
	bx r1
	.align 2, 0
